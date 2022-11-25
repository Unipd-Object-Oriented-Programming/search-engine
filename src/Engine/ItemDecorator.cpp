#include "ItemDecorator.h"

namespace Engine {

ItemDecorator::ItemDecorator(
    const Item::AbstractItem* item,
    const double score
)
    : item(item), score(score)
{
}

const Item::AbstractItem* ItemDecorator::getItem() const {
    return item;
}

double ItemDecorator::getScore() const {
    return score;
}

bool ItemDecorator::operator<(const ItemDecorator& item_decorator) const {
    return score > item_decorator.score;
}

}