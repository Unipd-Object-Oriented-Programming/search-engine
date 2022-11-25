#include "JsonRepository.h"

#include <stdexcept>

#include "../Converter/Json/Reader.h"
#include "../Converter/Json/Json.h"

namespace Item {
namespace Repository {

JsonRepository::JsonRepository(DataMapper::JsonFile data_mapper)
    : data_mapper(data_mapper)
{
    std::vector<AbstractItem*> items(data_mapper.load());
    for (
        std::vector<AbstractItem*>::const_iterator it = items.begin();
        it != items.end();
        it++
    ) {
        repository[(*it)->getIdentifier()] = *it;
    }
}

JsonRepository::~JsonRepository() {
    for (
        std::map<unsigned int, AbstractItem*>::const_iterator it = repository.begin();
        it != repository.end();
        it++
    ) {
        delete it->second;
    }
}

JsonRepository JsonRepository::fromPath(std::string path) {
    Converter::Json::Reader reader;
    Converter::Json::Json converter(reader);
    DataMapper::JsonFile data_mapper(path, converter);
    JsonRepository repository(data_mapper);
    return repository;
}

const DataMapper::JsonFile& JsonRepository::getDataMapper() const {
    return data_mapper;
}

const std::map<unsigned int, AbstractItem*>& JsonRepository::getRepository() const {
    return repository;
}

const std::string& JsonRepository::getPath() const {
    return data_mapper.getPath();
}

JsonRepository& JsonRepository::setPath(std::string path) {
    data_mapper.setPath(path);
    return *this;
}

JsonRepository& JsonRepository::create(AbstractItem* item) {
    repository[item->getIdentifier()] = item;
    return *this;
}

AbstractItem* JsonRepository::read(const unsigned int identifier) const {
    std::map<unsigned int, AbstractItem*>::const_iterator it = repository.find(identifier);
    if (it == repository.end()) {
        throw std::out_of_range("Trying to read an undefined id.");
    }
    return it->second;
}

JsonRepository& JsonRepository::update(AbstractItem* item) {
    return create(item);
}

JsonRepository& JsonRepository::remove(const unsigned int identifier) {
    std::map<unsigned int, AbstractItem*>::const_iterator it = repository.find(identifier);
    if (it != repository.end()) {
        delete it->second;
        repository.erase(it);
    }
    return *this;
}

std::vector<AbstractItem*> JsonRepository::readAll() const {
    std::vector<AbstractItem*> items;
    for (
        std::map<unsigned int, AbstractItem*>::const_iterator it = repository.begin();
        it != repository.end();
        it++
    ) {
        items.push_back(it->second);
    }
    return items;
}

JsonRepository& JsonRepository::store() {
    data_mapper.store(readAll());
    return *this;
}

}
}