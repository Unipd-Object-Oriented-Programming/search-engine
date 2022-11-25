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
    items.push_back(item);
    return *this;
}

Memory& Memory::remove(const Item::AbstractItem* item) {
    std::vector<const Item::AbstractItem*>::iterator position = std::find(items.begin(), items.end(), item);
    if (position != items.end()) {
        items.erase(position);
    }
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

    // Computes and sorts results
    for (
        std::vector<const Item::AbstractItem*>::const_iterator it = items.begin();
        it != items.end();
        it++
    ) {
        (*it)->accept(score_visitor);
        (*it)->accept(filter_visitor);
        if (filter_visitor.hasMatch() && score_visitor.getScore() > 0.0) {
            results.push_back(ItemDecorator(*it, score_visitor.getScore()));
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