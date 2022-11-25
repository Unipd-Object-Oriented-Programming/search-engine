#ifndef VIEW_WIDGET_LOOKUP_H
#define VIEW_WIDGET_LOOKUP_H

#include <QWidget>
#include <QPushButton>

#include "../Item/AbstractItem.h"

namespace View {

class WidgetLookup {
  private:
    const Item::AbstractItem* item;
    QWidget* widget;
    QPushButton* view_button;
    QPushButton* edit_button;
    QPushButton* delete_button;

  public:
    WidgetLookup(
        const Item::AbstractItem* item,
        QWidget* widget,
        QPushButton* view_button,
        QPushButton* edit_button,
        QPushButton* delete_button
    );
    const Item::AbstractItem* getItem() const;
    QWidget* getWidget() const;
    QPushButton* getViewButton() const;
    QPushButton* getEditButton() const;
    QPushButton* getDeleteButton() const;
};

}

#endif