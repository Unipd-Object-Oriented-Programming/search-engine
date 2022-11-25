#include <algorithm>

#include "Bundle.h"

namespace Item {

Bundle::Bundle(
    const unsigned int identifier,
    const std::string name,
    const std::string description,
    const std::string image_path,
    const std::string sku
)
    : AbstractProduct(identifier, name, description, image_path, sku)
{
}

const std::vector<const AbstractProduct*>& Bundle::getProducts() const {
    return products;
}

unsigned int Bundle::getSize() const {
    return products.size();
}

Bundle& Bundle::add(const AbstractProduct* product) {
    products.push_back(product);
    return *this;
}

Bundle& Bundle::remove(const AbstractProduct* product) {
    std::vector<const AbstractProduct*>::iterator position = std::find(products.begin(), products.end(), product);
    if (position != products.end()) {
        products.erase(position);
    }
    return *this;
}

Bundle& Bundle::clear() {
    products.clear();
    return *this;
}

unsigned int Bundle::getAvailability() const {
    if (products.empty()) {
        return 0;
    }
    unsigned int minimum_availability = products[0]->getAvailability();
    for (
        std::vector<const AbstractProduct *>::const_iterator it = products.begin();
        it != products.end();
        it++
    ) {
        const double product_availability = (*it)->getAvailability();
        if (product_availability < minimum_availability) {
            minimum_availability = product_availability;
        }
    }
    return minimum_availability;
}

double Bundle::getPrice() const {
    double price = 0.0;
    for (
        std::vector<const AbstractProduct *>::const_iterator it = products.begin();
        it != products.end();
        it++
    ) {
        price += (*it)->getPrice();
    }
    return price;
}

void Bundle::accept(IConstVisitor& visitor) const {
    visitor.visit(*this);
}

void Bundle::accept(IVisitor& visitor) {
    visitor.visit(*this);
}

}