#ifndef ITEM_CONVERTER_JSON_JSON_VISITOR_H
#define ITEM_CONVERTER_JSON_JSON_VISITOR_H

#include <QJsonObject>
#include "../../IConstVisitor.h"
#include "../../WebPage.h"
#include "../../Simple.h"
#include "../../Virtual.h"
#include "../../Bundle.h"

namespace Item {
namespace Converter {
namespace Json {

class JsonVisitor: public IConstVisitor {
  private:
    QJsonObject object;

  public:
    QJsonObject getObject() const;
    void visit(const WebPage& web_page);
    void visit(const Simple& simple);
    void visit(const Virtual& virtual_item);
    void visit(const Bundle& bundle);
};

}
}
}

#endif