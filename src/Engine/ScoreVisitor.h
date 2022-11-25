#ifndef ENGINE_SCORE_VISITOR_H
#define ENGINE_SCORE_VISITOR_H

#include "Query.h"
#include "../Service/StringFilter.h"
#include "../Item/IConstVisitor.h"
#include "../Item/WebPage.h"
#include "../Item/Simple.h"
#include "../Item/Virtual.h"
#include "../Item/Bundle.h"

namespace Engine {

class ScoreVisitor: public Item::IConstVisitor {
  private:
    const Query& query;
    const Service::StringFilter string_filter;
    double score;

  public:
    ScoreVisitor(const Query& query);
    const Query& getQuery() const;
    double getScore() const;
    virtual void visit(const Item::WebPage& web_page);
    virtual void visit(const Item::Simple& simple);
    virtual void visit(const Item::Virtual& virtual_item);
    virtual void visit(const Item::Bundle& bundle);
  
  private:
    double computeScore(const std::string& query, const std::string& text) const;
};

}

#endif