#ifndef ITEM_CONVERTER_JSON_IREADER_H
#define ITEM_CONVERTER_JSON_IREADER_H

#include <QJsonObject>

#include "../../AbstractItem.h"

namespace Item {
namespace Converter {
namespace Json {

class IReader {
  public:
    virtual ~IReader() {};
    virtual AbstractItem* read(const QJsonObject& object) = 0;
};

}
}
}

#endif