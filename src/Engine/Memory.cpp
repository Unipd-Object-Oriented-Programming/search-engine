#include <algorithm>

#include "Memory.h"
#include "ItemDecorator.h"
#include "ScoreVisitor.h"
#include "FilterVisitor.h"

namespace Engine {

Memory::Memory() {
}

Memory::~Memory() {
}

Memory& Memory::add(const Item::AbstractItem* item) {
    items.add(item);
    return *this;
}

Memory& Memory::remove(const Item::AbstractItem* item) {
    items.remove(item);
    return *this;
}

Memory& Memory::clear() {
    items.clear();
    return *this;
}

ResultSet Memory::search(const Query& query) const {
    ScoreVisitor score_visitor(query);
    FilterVisitor filter_visitor(query);
    std::vector<ItemDecorator> results;

    for (
        Service::Container<const Item::AbstractItem*>::Node* node = items.getHead();
        node != nullptr;
        node = node->getNext()
    ) {
        node->getData()->accept(score_visitor);
        node->getData()->accept(filter_visitor);
        if (filter_visitor.hasMatch() && score_visitor.getScore() > 0.0) {
            results.push_back(ItemDecorator(node->getData(), score_visitor.getScore()));
        }
    }
    std::sort(results.begin(), results.end());

    // Populates result set
    ResultSet result_set(results.size());
    for (unsigned int i = query.getOffset(); i < query.getOffset() + query.getSize(); i++) {
        if (results.size() <= i) {
            break;
        }
        result_set.add(results[i]);
    }

    return result_set;
}

}