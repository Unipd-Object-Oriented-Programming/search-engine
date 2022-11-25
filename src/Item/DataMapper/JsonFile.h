#ifndef ITEM_DATA_MAPPER_JSON_FILE_H
#define ITEM_DATA_MAPPER_JSON_FILE_H

#include <string>
#include <vector>

#include "../AbstractItem.h"
#include "../Converter/Json/Json.h"

namespace Item {
namespace DataMapper {

class JsonFile {
  private:
    std::string path;
    Converter::Json::Json& converter;

  public:
    JsonFile(const std::string& path, Converter::Json::Json& converter);
    static JsonFile fromPath(const std::string& path);
    const std::string& getPath() const;
    JsonFile& setPath(const std::string& path);
    const Converter::Json::Json& getConverter() const;
    JsonFile& store(const std::vector<AbstractItem*> items);
    std::vector<AbstractItem*> load();
};

}
}

#endif