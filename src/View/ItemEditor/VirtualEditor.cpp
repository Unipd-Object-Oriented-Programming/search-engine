#include "VirtualEditor.h"

#include <QFormLayout>

#include "../../Item/Virtual.h"

namespace View {
namespace ItemEditor {

VirtualEditor::VirtualEditor(QWidget* parent)
    : AbstractItemEditor(parent)
{
    QFormLayout* form = new QFormLayout(this);
    form->setObjectName("web-page-form");
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);

    sku_input = new QLineEdit();
    sku_input->setObjectName("sku-input");
    form->addRow("SKU", sku_input);

    availability_input = new QSpinBox();
    availability_input->setObjectName("availability-input");
    availability_input->setMinimum(0);
    availability_input->setMaximum(INT_MAX);
    form->addRow("availability", availability_input);

    price_input = new QDoubleSpinBox();
    price_input->setObjectName("price-input");
    price_input->setMinimum(0.0);
    price_input->setMaximum(__DBL_MAX__);
    form->addRow("price", price_input);
}

VirtualEditor::~VirtualEditor() {
}

Item::AbstractItem* VirtualEditor::create(
    const unsigned int identifier,
    const QString& name,
    const QString& description,
    const QString& image_path
) const {
    return new Item::Virtual(
        identifier,
        name.toStdString(),
        description.toStdString(),
        image_path.toStdString(),
        sku_input->text().toStdString(),
        availability_input->value(),
        price_input->value()
    );
}

void VirtualEditor::setValues(const Item::Virtual& virtual_item) {
    sku_input->setText(QString::fromStdString(virtual_item.getSku()));
    availability_input->setValue(virtual_item.getAvailability());
    price_input->setValue(virtual_item.getPrice());
}

}
}