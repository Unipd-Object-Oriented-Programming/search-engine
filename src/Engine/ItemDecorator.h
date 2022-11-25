#ifndef ENGINE_ITEM_DECORATOR_H
#define ENGINE_ITEM_DECORATOR_H

#include "../Item/AbstractItem.h"

namespace Engine {

class ItemDecorator {
  private:
    const Item::AbstractItem* item;
    double score;

  public:
    ItemDecorator(const Item::AbstractItem* item, const double score);
    const Item::AbstractItem* getItem() const;
    double getScore() const;
    bool operator<(const ItemDecorator& item_decorator) const;
};

}

#endif