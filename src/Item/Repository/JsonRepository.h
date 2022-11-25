#ifndef ITEM_REPOSITORY_JSON_REPOSITORY_H
#define ITEM_REPOSITORY_JSON_REPOSITORY_H

#include <string>
#include <map>

#include "IRepository.h"
#include "../DataMapper/JsonFile.h"

namespace Item {
namespace Repository {

class JsonRepository: public IRepository {
  private:
    DataMapper::JsonFile data_mapper;
    std::map<unsigned int, AbstractItem*> repository;

  public:
    JsonRepository(DataMapper::JsonFile data_mapper);
    virtual ~JsonRepository();
    static JsonRepository fromPath(const std::string path);
    const DataMapper::JsonFile& getDataMapper() const;
    const std::map<unsigned int, AbstractItem*>& getRepository() const;
    const std::string& getPath() const;
    JsonRepository& setPath(std::string path);
    virtual JsonRepository& create(AbstractItem* item);
    virtual AbstractItem* read(const unsigned int identifier) const;
    virtual JsonRepository& update(AbstractItem* item);
    virtual JsonRepository& remove(const unsigned int identifier);
    virtual std::vector<AbstractItem*> readAll() const;
    JsonRepository& store();
};

}
}

#endif