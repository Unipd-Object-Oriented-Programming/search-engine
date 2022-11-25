#ifndef VIEW_ITEM_RENDERER_LIST_ITEM_H
#define VIEW_ITEM_RENDERER_LIST_ITEM_H

#include "IItemRenderer.h"

#include "../ResultsWidget.h"

namespace View {
namespace ItemRenderer {

class ListItem: public IItemRenderer {
  private:
    bool has_controls;
    QWidget* widget;
    QPushButton* view_button;
    QPushButton* edit_button;
    QPushButton* delete_button;

  public:
    ListItem();
    virtual void visit(const Item::WebPage& web_page);
    virtual void visit(const Item::Simple& simple);
    virtual void visit(const Item::Virtual& virtual_item);
    virtual void visit(const Item::Bundle& bundle);
    bool hasControls() const;
    void setHasControls(const bool has_controls);
    virtual QWidget* getWidget() const;
    virtual QPushButton* getViewButton() const;
    virtual QPushButton* getEditButton() const;
    virtual QPushButton* getDeleteButton() const;
};

}
}

#endif