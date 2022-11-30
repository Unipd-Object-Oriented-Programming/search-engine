#include "Reader.h"

#include <stdexcept>
#include <QJsonArray>

#include "../../WebPage.h"
#include "../../Simple.h"
#include "../../Virtual.h"
#include "../../Bundle.h"
#include "Service/Logger/Singleton.h"

namespace Item {
namespace Converter {
namespace Json {

const std::map<unsigned int, AbstractItem*>& Reader::getCache() const {
    return cache;
}

Reader& Reader::clear() {
    cache.clear();
    return *this;
}

AbstractItem* Reader::read(const QJsonObject& object) {
    QJsonValue type = object.value("type");
    if (type.isUndefined()) {
        Service::Logger::Singleton::get().error("Missing item type.");
        throw std::invalid_argument("Missing item type.");
    }
    const unsigned int identifier = object.value("id").toInt();
    if (cache.count(identifier) > 0) {
        return cache[identifier];
    }
    else if (type.toString().compare("webPage") == 0) {
        cache[identifier] = readWebPage(object);
    }
    else if (type.toString().compare("simple") == 0) {
        cache[identifier] = readSimple(object);
    }
    else if (type.toString().compare("virtual") == 0) {
        cache[identifier] = readVirtual(object);
    }
    else if (type.toString().compare("bundle") == 0) {
        cache[identifier] = readBundle(object);
    }
    else {
        Service::Logger::Singleton::get().error("Unknown item type.");
        throw std::invalid_argument("Unknown type.");
    }
    return cache[identifier];
}

AbstractItem* Reader::readWebPage(const QJsonObject& object) const {
    return new WebPage(
        object.value("id").toInt(),
        object.value("name").toString().toStdString(),
        object.value("description").toString().toStdString(),
        object.value("imagePath").toString().toStdString(),
        object.value("url").toString().toStdString()
    );
}

AbstractItem* Reader::readSimple(const QJsonObject& object) const {
    return new Simple(
        object.value("id").toInt(),
        object.value("name").toString().toStdString(),
        object.value("description").toString().toStdString(),
        object.value("imagePath").toString().toStdString(),
        object.value("sku").toString().toStdString(),
        object.value("availability").toInt(),
        object.value("price").toDouble()
    );
}

AbstractItem* Reader::readVirtual(const QJsonObject& object) const {
    return new Virtual(
        object.value("id").toInt(),
        object.value("name").toString().toStdString(),
        object.value("description").toString().toStdString(),
        object.value("imagePath").toString().toStdString(),
        object.value("sku").toString().toStdString(),
        object.value("availability").toInt(),
        object.value("price").toDouble()
    );
}

AbstractItem* Reader::readBundle(const QJsonObject& object) {
    Bundle* bundle = new Bundle(
        object.value("id").toInt(),
        object.value("name").toString().toStdString(),
        object.value("description").toString().toStdString(),
        object.value("imagePath").toString().toStdString(),
        object.value("sku").toString().toStdString()
    );
    QJsonArray json_products = object.value("products").toArray();
    for (const QJsonValue& value: json_products) {
        QJsonObject json_object = value.toObject();
        AbstractItem* item = read(json_object);
        AbstractProduct* product = dynamic_cast<AbstractProduct*>(item);
        if (!product) {
            Service::Logger::Singleton::get().error("Found a non-product inside a bundle.");
            throw std::invalid_argument("Found a non-product inside a bundle.");
        }
        bundle->add(product);
    }
    return bundle;
}

}
}
}
