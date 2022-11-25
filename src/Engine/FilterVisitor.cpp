#include "FilterVisitor.h"

#include "../Item/AbstractProduct.h"

namespace Engine {

FilterVisitor::FilterVisitor(const Query& query)
    : query(query), has_match(false)
{
}

const Query& FilterVisitor::getQuery() const {
    return query;
}

bool FilterVisitor::hasMatch() const {
    return has_match;
}

void FilterVisitor::visit(const Item::WebPage& web_page) {
    has_match = web_page.getName().find(query.getFilter()) != std::string::npos
        || web_page.getDescription().find(query.getFilter()) != std::string::npos
    ;
}

void FilterVisitor::visit(const Item::Simple& simple) {
    has_match = simple.getName().find(query.getFilter()) != std::string::npos
        || simple.getDescription().find(query.getFilter()) != std::string::npos
        || simple.getSku().find(query.getFilter()) != std::string::npos
    ;
}

void FilterVisitor::visit(const Item::Virtual& virtual_item) {
    has_match = virtual_item.getName().find(query.getFilter()) != std::string::npos
        || virtual_item.getDescription().find(query.getFilter()) != std::string::npos
        || virtual_item.getSku().find(query.getFilter()) != std::string::npos
    ;
}

void FilterVisitor::visit(const Item::Bundle& bundle) {
    has_match = bundle.getName().find(query.getFilter()) != std::string::npos
        || bundle.getDescription().find(query.getFilter()) != std::string::npos
        || bundle.getSku().find(query.getFilter()) != std::string::npos
    ;
    if (has_match) {
        return;
    }
    for (
        std::vector<const Item::AbstractProduct*>::const_iterator it = bundle.getProducts().begin();
        it != bundle.getProducts().end();
        it++
    ) {
        (*it)->accept(*this);
        if (has_match) {
            return;
        }
    }
}

}