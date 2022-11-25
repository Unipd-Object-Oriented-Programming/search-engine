#ifndef ITEM_CONVERTER_JSON_READER_H
#define ITEM_CONVERTER_JSON_READER_H

#include <map>
#include <QJsonObject>

#include "IReader.h"

namespace Item {
namespace Converter {
namespace Json {

class Reader: public IReader {
  private:
    std::map<unsigned int, AbstractItem*> cache;

  public:
    const std::map<unsigned int, AbstractItem*>& getCache() const;
    Reader& clear();
    virtual AbstractItem* read(const QJsonObject& object);

  private:
    AbstractItem* readWebPage(const QJsonObject& object) const;
    AbstractItem* readSimple(const QJsonObject& object) const;
    AbstractItem* readVirtual(const QJsonObject& object) const;
    AbstractItem* readBundle(const QJsonObject& object);
};

}
}
}

#endif