#include "ResultSet.h"

namespace Engine {

ResultSet::ResultSet(const unsigned int total)
    : total(total)
{
}

unsigned int ResultSet::getTotal() const {
    return total;
}

const std::vector<ItemDecorator>& ResultSet::getItems() const {
    return items;
}

ResultSet& ResultSet::add(const ItemDecorator item) {
    items.push_back(item);
    return *this;
}

}