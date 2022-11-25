#include "AbstractItem.h"

namespace Item {

AbstractItem::AbstractItem(
    const unsigned int identifier,
    const std::string name,
    const std::string description,
    const std::string image_path
)
    : identifier(identifier),
    name(name),
    description(description),
    image_path(image_path)
{
}

AbstractItem::~AbstractItem() {
}

unsigned int AbstractItem::getIdentifier() const {
    return identifier;
}

const std::string& AbstractItem::getName() const {
    return name;
}

AbstractItem& AbstractItem::setName(const std::string name) {
    this->name = name;
    return *this;
}

const std::string& AbstractItem::getDescription() const {
    return description;
}

AbstractItem& AbstractItem::setDescription(const std::string description) {
    this->description = description;
    return *this;
}

const std::string& AbstractItem::getImagePath() const {
    return image_path;
}

AbstractItem& AbstractItem::setImagePath(const std::string image_path) {
    this->image_path = image_path;
    return *this;
}

}