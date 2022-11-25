#ifndef ITEM_BUNDLE_H
#define ITEM_BUNDLE_H

#include <vector>

#include "AbstractProduct.h"

namespace Item {

class Bundle: public AbstractProduct {
  private:
    std::vector<const AbstractProduct*> products;

  public:
    Bundle(
        const unsigned int identifier,
        const std::string name,
        const std::string description,
        const std::string image_path,
        const std::string sku
    );

    const std::vector<const AbstractProduct*>& getProducts() const;
    unsigned int getSize() const;
    Bundle& add(const AbstractProduct* product);
    Bundle& remove(const AbstractProduct* product);
    Bundle& clear();
    virtual unsigned int getAvailability() const;
    virtual double getPrice() const;
    virtual void accept(IConstVisitor& visitor) const;
    virtual void accept(IVisitor& visitor);
};

}

#endif