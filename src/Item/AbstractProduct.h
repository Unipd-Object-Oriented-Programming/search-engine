#ifndef ITEM_ABSTRACT_PRODUCT_H
#define ITEM_ABSTRACT_PRODUCT_H

#include <string>

#include "AbstractItem.h"

namespace Item {

class AbstractProduct: public AbstractItem {
  private:
    std::string sku;

  protected:
    AbstractProduct(
        const unsigned int identifier,
        const std::string name,
        const std::string description,
        const std::string image_path,
        const std::string sku
    );

  public:
    const std::string& getSku() const;
    AbstractProduct& setSku(const std::string sku);
    virtual unsigned int getAvailability() const = 0;
    bool isAvailable() const;
    virtual double getPrice() const = 0;
};

}

#endif