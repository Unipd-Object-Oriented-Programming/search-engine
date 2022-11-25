#ifndef VIEW_ITEM_EDITOR_BUNDLE_H
#define VIEW_ITEM_EDITOR_BUNDLE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QVector>

#include "AbstractItemEditor.h"
#include "ItemSelectorWidget.h"
#include "../../Item/Repository/JsonRepository.h"

namespace View {
namespace ItemEditor {

class BundleEditor: public AbstractItemEditor {
  private:
    Item::Repository::JsonRepository* repository;
    QLineEdit* sku_input;
    QSpinBox* products_number_input;
    QVector<ItemSelectorWidget*> products;
    QVBoxLayout* products_container;

  public:
    BundleEditor(
        Item::Repository::JsonRepository* repository,
        QWidget* parent = 0
    );
    virtual ~BundleEditor();
    virtual Item::AbstractItem* create(
        const unsigned int identifier,
        const QString& name,
        const QString& description,
        const QString& image_path
    ) const;
    void setValues(const Item::Bundle& bundle);

  public slots:
    void showProductSelectors(int products_number);
};

}
}

#endif