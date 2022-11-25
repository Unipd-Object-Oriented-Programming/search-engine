#ifndef ITEM_REPOSITORY_I_REPOSITORY_H
#define ITEM_REPOSITORY_I_REPOSITORY_H

#include <vector>

#include "../AbstractItem.h"

namespace Item {
namespace Repository {

class IRepository {
  public:
    virtual ~IRepository() = default;
    virtual IRepository& create(AbstractItem *item) = 0 ;
    virtual AbstractItem* read(const unsigned int identifier) const = 0;
    virtual IRepository& update(AbstractItem* item) = 0;
    virtual IRepository& remove(const unsigned int identifier) = 0;
    virtual std::vector<AbstractItem*> readAll() const = 0;
};

}
}

#endif