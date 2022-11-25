#ifndef ITEM_I_CONST_VISITOR_H
#define ITEM_I_CONST_VISITOR_H

namespace Item {

class WebPage;
class Simple;
class Virtual;
class Bundle;

class IConstVisitor {
  public:
    virtual ~IConstVisitor() {};
    virtual void visit(const WebPage& web_page) = 0;
    virtual void visit(const Simple& simple) = 0;
    virtual void visit(const Virtual& virtual_item) = 0;
    virtual void visit(const Bundle& bundle) = 0;
};

}

#endif