#include "Virtual.h"

namespace Item {

Virtual::Virtual(
    const unsigned int identifier,
    const std::string name,
    const std::string description,
    const std::string image_path,
    const std::string sku,
    const unsigned int availability,
    const double price
)
    : Simple(identifier, name, description, image_path, sku, availability, price)
{
}

void Virtual::accept(IConstVisitor& visitor) const {
    visitor.visit(*this);
}

void Virtual::accept(IVisitor& visitor) {
    visitor.visit(*this);
}

}