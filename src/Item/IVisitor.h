#ifndef ITEM_I_VISITOR_H
#define ITEM_I_VISITOR_H

namespace Item {

class WebPage;
class Simple;
class Virtual;
class Bundle;

class IVisitor {
  public:
    virtual ~IVisitor() {};
    virtual void visit(WebPage& web_page) = 0;
    virtual void visit(Simple& simple) = 0;
    virtual void visit(Virtual& virtual_item) = 0;
    virtual void visit(Bundle& bundle) = 0;
};

}

#endif