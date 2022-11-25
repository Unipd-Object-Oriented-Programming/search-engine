#include "Simple.h"

namespace Item {

Simple::Simple(
    const unsigned int identifier,
    const std::string name,
    const std::string description,
    const std::string image_path,
    const std::string sku,
    const unsigned int availability,
    const double price
)
    : AbstractProduct(identifier, name, description, image_path, sku),
    availability(availability),
    price(price)
{
}

unsigned int Simple::getAvailability() const {
    return availability;
}

Simple& Simple::setAvailability(const unsigned int availability) {
    this->availability = availability;
    return *this;
}

double Simple::getPrice() const {
    return price;
}

Simple& Simple::setPrice(const double price) {
    this->price = price;
    return *this;
}

void Simple::accept(IConstVisitor& visitor) const {
    visitor.visit(*this);
}

void Simple::accept(IVisitor& visitor) {
    visitor.visit(*this);
}

}