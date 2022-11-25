#include "BundleEditor.h"

#include <QFormLayout>

#include "../../Item/Bundle.h"

namespace View {
namespace ItemEditor {

BundleEditor::BundleEditor(
        Item::Repository::JsonRepository* repository,
        QWidget* parent
    )
    : AbstractItemEditor(parent), repository(repository)
{
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setObjectName("bundle");
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QFormLayout* form = new QFormLayout();
    form->setObjectName("form");
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);
    vbox->addLayout(form);

    sku_input = new QLineEdit();
    sku_input->setObjectName("sku-input");
    form->addRow("SKU", sku_input);

    products_number_input = new QSpinBox();
    products_number_input->setObjectName("products-number-input");
    products_number_input->setMinimum(1);
    products_number_input->setMaximum(10);
    form->addRow("products", products_number_input);

    products_container = new QVBoxLayout();
    products_container->setObjectName("products-container");
    products_container->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(products_container);
    showProductSelectors(products_number_input->value());

    // Connects signals
    connect(products_number_input, QOverload<int>::of(&QSpinBox::valueChanged), this, &BundleEditor::showProductSelectors);
}

BundleEditor::~BundleEditor() {
}

Item::AbstractItem* BundleEditor::create(
    const unsigned int identifier,
    const QString& name,
    const QString& description,
    const QString& image_path
) const {
    Item::Bundle* item = new Item::Bundle(
        identifier,
        name.toStdString(),
        description.toStdString(),
        image_path.toStdString(),
        sku_input->text().toStdString()
    );
    for (
        QVector<ItemSelectorWidget*>::const_iterator it = products.begin();
        it != products.end();
        it++
    ) {
        try {
            Item::AbstractProduct* product = dynamic_cast<Item::AbstractProduct*>((*it)->getItem());
            if (product) {
                item->add(product);
            }
        }
        catch (const std::out_of_range& e) {
        }
    }
    return item;
}

void BundleEditor::setValues(const Item::Bundle& bundle) {
    sku_input->setText(QString::fromStdString(bundle.getSku()));
    showProductSelectors(bundle.getProducts().size());
    for (unsigned int i = 0; i < bundle.getProducts().size(); i++) {
        products[i]->setIdentifier(bundle.getProducts()[i]->getIdentifier());
    }
}

void BundleEditor::showProductSelectors(int products_number) {
    while (products.length() > products_number) {
        delete products.takeLast();
    }
    while (products.length() < products_number) {
        ItemSelectorWidget* selector = new ItemSelectorWidget(repository);
        products.push_back(selector);
        products_container->addWidget(selector);
    }
}

}
}