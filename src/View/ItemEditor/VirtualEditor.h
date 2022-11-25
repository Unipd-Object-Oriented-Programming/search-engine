#ifndef VIEW_ITEM_EDITOR_VIRTUAL_H
#define VIEW_ITEM_EDITOR_VIRTUAL_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>

#include "AbstractItemEditor.h"

namespace View {
namespace ItemEditor {

class VirtualEditor: public AbstractItemEditor {
  private:
    QLineEdit* sku_input;
    QSpinBox* availability_input;
    QDoubleSpinBox* price_input;

  public:
    VirtualEditor(QWidget* parent = 0);
    virtual ~VirtualEditor();
    virtual Item::AbstractItem* create(
        const unsigned int identifier,
        const QString& name,
        const QString& description,
        const QString& image_path
    ) const;
    void setValues(const Item::Virtual& virtual_item);
};

}
}

#endif