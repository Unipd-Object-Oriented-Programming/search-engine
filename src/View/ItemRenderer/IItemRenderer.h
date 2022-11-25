#ifndef VIEW_ITEM_RENDERER_I_ITEM_RENDERER_H
#define VIEW_ITEM_RENDERER_I_ITEM_RENDERER_H

#include <QWidget>
#include <QPushButton>

#include "../../Item/AbstractItem.h"
#include "../../Item/IConstVisitor.h"

namespace View {
namespace ItemRenderer {

class IItemRenderer: public Item::IConstVisitor {
  public:
    virtual QWidget* getWidget() const = 0;
    virtual QPushButton* getViewButton() const = 0;
    virtual QPushButton* getEditButton() const = 0;
    virtual QPushButton* getDeleteButton() const = 0;
};

}
}

#endif