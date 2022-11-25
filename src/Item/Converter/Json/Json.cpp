#include "Json.h"
#include "JsonVisitor.h"
#include "../../Simple.h"

namespace Item {
namespace Converter {
namespace Json {

Json::Json(IReader& reader)
    : reader(reader)
{
}

const IReader& Json::getReader() const {
    return reader;
}

QJsonObject Json::fromObject(const AbstractItem& item) const {
    JsonVisitor json_visitor;
    item.accept(json_visitor);
    return json_visitor.getObject();
}

AbstractItem* Json::toObject(const QJsonObject& json) const {
    return reader.read(json);
}

}
}
}