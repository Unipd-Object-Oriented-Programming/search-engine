#ifndef VIEW_ITEM_RENDERER_CARD_H
#define VIEW_ITEM_RENDERER_CARD_H

#include "IItemRenderer.h"

#include "../ResultsWidget.h"

namespace View {
namespace ItemRenderer {

class Card: public IItemRenderer {
  private:
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