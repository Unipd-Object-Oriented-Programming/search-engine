#ifndef ENGINE_FILTER_VISITOR_H
#define ENGINE_FILTER_VISITOR_H

#include "Query.h"
#include "../Item/IConstVisitor.h"
#include "../Item/WebPage.h"
#include "../Item/Simple.h"
#include "../Item/Virtual.h"
#include "../Item/Bundle.h"

namespace Engine {

class FilterVisitor: public Item::IConstVisitor {
  private:
    const Query& query;
    bool has_match;

  public:
    FilterVisitor(const Query& query);
    const Query& getQuery() const;
    bool hasMatch() const;
    virtual void visit(const Item::WebPage& web_page);
    virtual void visit(const Item::Simple& simple);
    virtual void visit(const Item::Virtual& virtual_item);
    virtual void visit(const Item::Bundle& bundle);
};

}

#endif