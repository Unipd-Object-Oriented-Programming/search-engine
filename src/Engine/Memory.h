#ifndef ENGINE_MEMORY_H
#define ENGINE_MEMORY_H

#include "IEngine.h"

#include "../Service/Container.h"
#include "../Item/AbstractItem.h"
#include "Query.h"
#include "ResultSet.h"

namespace Engine {

class Memory: public IEngine {
  private:
    Service::Container<const Item::AbstractItem*> items;

  public:
    Memory();
    virtual ~Memory();
    virtual Memory& add(const Item::AbstractItem* item);
    virtual Memory& remove(const Item::AbstractItem* item);
    virtual Memory& clear();
    virtual ResultSet search(const Query& query) const;
};

}

#endif