#ifndef ITEM_CONVERTER_JSON_JSON_H
#define ITEM_CONVERTER_JSON_JSON_H

#include <QJsonObject>
#include "../../AbstractItem.h"
#include "IReader.h"

namespace Item {
namespace Converter {
namespace Json {

class Json {
  private:
    IReader& reader;

  public:
    Json(IReader& reader);
    const IReader& getReader() const;
    QJsonObject fromObject(const AbstractItem& item) const;
    AbstractItem* toObject(const QJsonObject& json) const;
};

}
}
}

#endif