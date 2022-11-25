#ifndef ITEM_SIMPLE_H
#define ITEM_SIMPLE_H

#include "AbstractProduct.h"

namespace Item {

class Simple: public AbstractProduct {
  private:
    unsigned int availability;
    double price;

  public:
    Simple(
        const unsigned int identifier,
        const std::string name,
        const std::string description,
        const std::string image_path,
        const std::string sku,
        const unsigned int availability,
        const double price
    );

    virtual unsigned int getAvailability() const;
    Simple& setAvailability(const unsigned int availability);
    virtual double getPrice() const;
    Simple& setPrice(const double price);
    virtual void accept(IConstVisitor& visitor) const;
    virtual void accept(IVisitor& visitor);
};

}

#endif