#ifndef ITEM_VIRTUAL_H
#define ITEM_VIRTUAL_H

#include "Simple.h"

namespace Item {

class Virtual: public Simple {
  public:
    Virtual(
        const unsigned int identifier,
        const std::string name,
        const std::string description,
        const std::string image_path,
        const std::string sku,
        const unsigned int availability,
        const double price
    );
    virtual void accept(IConstVisitor& visitor) const;
    virtual void accept(IVisitor& visitor);
};

}

#endif