#include "JsonVisitor.h"

#include <QJsonArray>

namespace Item {
namespace Converter {
namespace Json {

QJsonObject JsonVisitor::getObject() const {
    return object;
}

void JsonVisitor::visit(const WebPage& web_page) {
    QJsonObject web_page_object;
    web_page_object.insert("type", QJsonValue::fromVariant("webPage"));
    web_page_object.insert("id", QJsonValue::fromVariant(web_page.getIdentifier()));
    web_page_object.insert("name", QJsonValue::fromVariant(web_page.getName().c_str()));
    web_page_object.insert("description", QJsonValue::fromVariant(web_page.getDescription().c_str()));
    web_page_object.insert("imagePath", QJsonValue::fromVariant(web_page.getImagePath().c_str()));
    web_page_object.insert("url", QJsonValue::fromVariant(web_page.getUrl().c_str()));
    object = web_page_object;
}

void JsonVisitor::visit(const Simple& simple) {
    QJsonObject simple_object;
    simple_object.insert("type", QJsonValue::fromVariant("simple"));
    simple_object.insert("id", QJsonValue::fromVariant(simple.getIdentifier()));
    simple_object.insert("name", QJsonValue::fromVariant(simple.getName().c_str()));
    simple_object.insert("description", QJsonValue::fromVariant(simple.getDescription().c_str()));
    simple_object.insert("imagePath", QJsonValue::fromVariant(simple.getImagePath().c_str()));
    simple_object.insert("sku", QJsonValue::fromVariant(simple.getSku().c_str()));
    simple_object.insert("availability", QJsonValue::fromVariant(simple.getAvailability()));
    simple_object.insert("price", QJsonValue::fromVariant(simple.getPrice()));
    object = simple_object;
}

void JsonVisitor::visit(const Virtual& virtual_item) {
    QJsonObject virtual_object;
    virtual_object.insert("type", QJsonValue::fromVariant("virtual"));
    virtual_object.insert("id", QJsonValue::fromVariant(virtual_item.getIdentifier()));
    virtual_object.insert("name", QJsonValue::fromVariant(virtual_item.getName().c_str()));
    virtual_object.insert("description", QJsonValue::fromVariant(virtual_item.getDescription().c_str()));
    virtual_object.insert("imagePath", QJsonValue::fromVariant(virtual_item.getImagePath().c_str()));
    virtual_object.insert("sku", QJsonValue::fromVariant(virtual_item.getSku().c_str()));
    virtual_object.insert("availability", QJsonValue::fromVariant(virtual_item.getAvailability()));
    virtual_object.insert("price", QJsonValue::fromVariant(virtual_item.getPrice()));
    object = virtual_object;
}

void JsonVisitor::visit(const Bundle& bundle) {
    QJsonObject bundle_object;
    QJsonArray products;
    bundle_object.insert("type", QJsonValue::fromVariant("bundle"));
    bundle_object.insert("id", QJsonValue::fromVariant(bundle.getIdentifier()));
    bundle_object.insert("name", QJsonValue::fromVariant(bundle.getName().c_str()));
    bundle_object.insert("description", QJsonValue::fromVariant(bundle.getDescription().c_str()));
    bundle_object.insert("imagePath", QJsonValue::fromVariant(bundle.getImagePath().c_str()));
    bundle_object.insert("sku", QJsonValue::fromVariant(bundle.getSku().c_str()));
    for (
        std::vector<const AbstractProduct *>::const_iterator it = bundle.getProducts().begin();
        it != bundle.getProducts().end();
        it++
    ) {
        (*it)->accept(*this);
        products.push_back(object);
    }
    bundle_object.insert("products", products);
    object = bundle_object;
}

}
}
}