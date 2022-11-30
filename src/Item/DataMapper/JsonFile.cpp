#include "JsonFile.h"
#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

#include "../../Service/Logger/Singleton.h"
#include "../Converter/Json/Reader.h"

namespace Item {
namespace DataMapper {

JsonFile::JsonFile(const std::string& path, Converter::Json::Json& converter)
    : path(path), converter(converter)
{
}

JsonFile JsonFile::fromPath(const std::string& path) {
    Converter::Json::Reader reader;
    Converter::Json::Json converter(reader);
    JsonFile data_mapper(path, converter);
    return data_mapper;
}

const std::string& JsonFile::getPath() const {
    return path;
}

JsonFile& JsonFile::setPath(const std::string& path) {
    this->path = path;
    return *this;
}

const Converter::Json::Json& JsonFile::getConverter() const {
    return converter;
}

// @todo check errors
JsonFile& JsonFile::store(const std::vector<AbstractItem*> items) {
    QJsonArray json_items;
    for (
        std::vector<AbstractItem*>::const_iterator it = items.begin();
        it != items.end();
        it++
    ) {
        json_items.push_back(converter.fromObject(**it));
    }
    QJsonDocument document(json_items);
    QFile json_file(path.c_str());
    json_file.open(QFile::WriteOnly);
    json_file.write(document.toJson());
    json_file.close();
    return *this;
}

// @todo check errors
std::vector<AbstractItem*> JsonFile::load() {
    std::vector<AbstractItem*> items;
    QFile json_file(path.c_str());
    json_file.open(QFile::ReadOnly);
    QByteArray data = json_file.readAll();
    json_file.close();
    QJsonDocument document = QJsonDocument::fromJson(data);
    QJsonArray json_items = document.array();

    for (const QJsonValue& value: json_items) {
        QJsonObject json_object = value.toObject();
        items.push_back(converter.toObject(json_object));
    }
    return items;
}

}
}
