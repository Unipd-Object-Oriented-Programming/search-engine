#include "AbstractProduct.h"

namespace Item {

AbstractProduct::AbstractProduct(
    const unsigned int identifier,
    const std::string name,
    const std::string description,
    const std::string image_path,
    const std::string sku
)
    : AbstractItem(identifier, name, description, image_path),
    sku(sku)
{
}

const std::string& AbstractProduct::getSku() const {
    return sku;
}

AbstractProduct& AbstractProduct::setSku(const std::string sku) {
    this->sku = sku;
    return *this;
}

bool AbstractProduct::isAvailable() const {
    return getAvailability() > 0;
}

}