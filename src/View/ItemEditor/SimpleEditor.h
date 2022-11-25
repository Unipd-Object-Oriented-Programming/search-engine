#ifndef VIEW_ITEM_EDITOR_SIMPLE_H
#define VIEW_ITEM_EDITOR_SIMPLE_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>

#include "AbstractItemEditor.h"

namespace View {
namespace ItemEditor {

class SimpleEditor: public AbstractItemEditor {
  private:
    QLineEdit* sku_input;
    QSpinBox* availability_input;
    QDoubleSpinBox* price_input;

  public:
    SimpleEditor(QWidget* parent = 0);
    virtual ~SimpleEditor();
    virtual Item::AbstractItem* create(
        const unsigned int identifier,
        const QString& name,
        const QString& description,
        const QString& image_path
    ) const;
    void setValues(const Item::Simple& simple);
};

}
}

#endif