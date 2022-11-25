#ifndef ENGINE_RESULT_SET_H
#define ENGINE_RESULT_SET_H

#include <vector>

#include "ItemDecorator.h"

namespace Engine {

class ResultSet {
  private:
    const unsigned int total;
    std::vector<ItemDecorator> items;

  public:
    ResultSet(const unsigned int total);
    unsigned int getTotal() const;
    const std::vector<ItemDecorator>& getItems() const;
    ResultSet& add(const ItemDecorator item);
};

}

#endif