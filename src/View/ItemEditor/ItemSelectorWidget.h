#ifndef VIEW_ITEM_EDITOR_ITEM_SELECTOR_WIDGET_H
#define VIEW_ITEM_EDITOR_ITEM_SELECTOR_WIDGET_H

#include <QWidget>
#include <QSpinBox>

#include "../../Item/Repository/JsonRepository.h"
#include "../ItemRenderer/ListItem.h"

namespace View {
namespace ItemEditor {

class ItemSelectorWidget: public QWidget {
    Q_OBJECT
  private:
    Item::Repository::JsonRepository* repository;
    QSpinBox* identifier_input;
    ItemRenderer::ListItem renderer;
    QVBoxLayout* vbox;
    QWidget* widget;

  public:
    ItemSelectorWidget(
        Item::Repository::JsonRepository* repository,
        QWidget* parent = 0
    );

    int getIdentifier() const;
    Item::AbstractItem* getItem() const;
    void setIdentifier(const int identifier);

  public slots:
    void updateView(int identifier);
};

}
}

#endif