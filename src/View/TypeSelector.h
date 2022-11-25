#ifndef VIEW_TYPE_SELECTOR_H
#define VIEW_TYPE_SELECTOR_H

#include <QComboBox>

#include "../Item/IConstVisitor.h"

namespace View {

class TypeSelector: public Item::IConstVisitor {
  private:
    QComboBox* combo_box;
  
  public:
    TypeSelector(QComboBox* combo_box);
    virtual void visit(const Item::WebPage& web_page);
    virtual void visit(const Item::Simple& simple);
    virtual void visit(const Item::Virtual& virtual_item);
    virtual void visit(const Item::Bundle& bundle);
    QComboBox* getComboBox();
    TypeSelector& setComboBox(QComboBox* combo_box);
};

}

#endif