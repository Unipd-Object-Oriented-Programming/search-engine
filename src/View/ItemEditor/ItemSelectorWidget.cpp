#include "ItemSelectorWidget.h"

#include <stdexcept>
#include <QVBoxLayout>

namespace View {
namespace ItemEditor {

ItemSelectorWidget::ItemSelectorWidget(
    Item::Repository::JsonRepository* repository,
    QWidget* parent
)
:   QWidget(parent), repository(repository)
{
    vbox = new QVBoxLayout(this);
    vbox->setObjectName("item-selector");
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    identifier_input = new QSpinBox();
    identifier_input->setObjectName("identifier-input");
    identifier_input->setMinimum(1);
    identifier_input->setMaximum(INT_MAX);
    vbox->addWidget(identifier_input);
    widget = nullptr;
    updateView(identifier_input->value());

    // Connect signals
    connect(identifier_input, QOverload<int>::of(&QSpinBox::valueChanged), this, &ItemSelectorWidget::updateView);
}

int ItemSelectorWidget::getIdentifier() const {
    return identifier_input->value();
}

Item::AbstractItem* ItemSelectorWidget::getItem() const {
    return repository->read(getIdentifier());
}

void ItemSelectorWidget::updateView(int identifier) {
    try {
        if (widget != nullptr) {
            delete widget;
        }
        Item::AbstractItem* item = repository->read(identifier);
        renderer.setHasControls(false);
        item->accept(renderer);
        widget = renderer.getWidget();
        vbox->addWidget(widget);
    }
    catch (const std::out_of_range& e) {
        widget = nullptr;
    }
}

void ItemSelectorWidget::setIdentifier(const int identifier) {
    identifier_input->setValue(identifier);
}

}
}