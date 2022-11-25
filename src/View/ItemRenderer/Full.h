#ifndef VIEW_ITEM_RENDERER_FULL_H
#define VIEW_ITEM_RENDERER_FULL_H

#include "IItemRenderer.h"
#include "ListItem.h"

namespace View {
namespace ItemRenderer {

class Full: public IItemRenderer {
  private:
    ListItem list_item;
    QWidget* widget;
    QPushButton* view_button;
    QPushButton* edit_button;
    QPushButton* delete_button;

  public:
    virtual void visit(const Item::WebPage& web_page);
    virtual void visit(const Item::Simple& simple);
    virtual void visit(const Item::Virtual& virtual_item);
    virtual void visit(const Item::Bundle& bundle);
    virtual QWidget* getWidget() const;
    virtual QPushButton* getViewButton() const;
    virtual QPushButton* getEditButton() const;
    virtual QPushButton* getDeleteButton() const;  
};

}
}

#endif