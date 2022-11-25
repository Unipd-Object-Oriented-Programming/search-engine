#include "EditWidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QComboBox>

#include "SearchWidget.h"
#include "TypeSelector.h"
#include "ItemEditor/WebPageEditor.h"
#include "ItemEditor/SimpleEditor.h"
#include "ItemEditor/VirtualEditor.h"
#include "ItemEditor/BundleEditor.h"
#include "ItemEditor/ItemInjector.h"

namespace View {

EditWidget::EditWidget(
      MainWindow* main_window,
      Item::Repository::JsonRepository* repository,
      const Item::AbstractItem* subject
    )
    : main_window(main_window), subject(subject)
{
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setObjectName("widget-edit");
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* title = new QLabel("Item properties");
    title->setObjectName("title");
    vbox->addWidget(title);

    QFormLayout* form = new QFormLayout();
    form->setObjectName("properties-form");
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);
    vbox->addLayout(form);

    identifier_input = new QSpinBox();
    identifier_input->setObjectName("identifier-input");
    identifier_input->setMinimum(1);
    identifier_input->setMaximum(INT_MAX);
    if (subject != nullptr) {
        identifier_input->setValue(subject->getIdentifier());
    }
    form->addRow("identifier", identifier_input);

    name_input = new QLineEdit();
    name_input->setObjectName("name-input");
    if (subject != nullptr) {
        name_input->setText(QString::fromStdString(subject->getName()));
    }
    form->addRow("name", name_input);

    description_input = new QTextEdit();
    description_input->setObjectName("description-input");
    if (subject != nullptr) {
        description_input->setText(QString::fromStdString(subject->getDescription()));
    }
    form->addRow("description", description_input);

    QHBoxLayout* image_selector = new QHBoxLayout();
    image_selector->setObjectName("image-selector");
    image_selector->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    form->addRow("image", image_selector);

    image_input = new QLineEdit();
    image_input->setObjectName("image-input");
    if (subject != nullptr) {
        image_input->setText(QString::fromStdString(subject->getImagePath()));
    }
    image_selector->addWidget(image_input);

    QPushButton* select_image_button = new QPushButton("Select");
    select_image_button->setObjectName("select-image-button");
    image_selector->addWidget(select_image_button);

    QComboBox* type_input = new QComboBox();
    type_input->setObjectName("type-input");
    type_input->addItem("web page");
    type_input->addItem("simple");
    type_input->addItem("virtual");
    type_input->addItem("bundle");
    if (subject != nullptr) {
        TypeSelector type_selector(type_input);
        subject->accept(type_selector);
    }
    form->addRow("type", type_input);

    stacked_editor = new QStackedLayout();
    vbox->addLayout(stacked_editor);

    ItemEditor::WebPageEditor* web_page_editor = new ItemEditor::WebPageEditor();
    stacked_editor->addWidget(web_page_editor);
    editors.push_back(web_page_editor);

    ItemEditor::SimpleEditor* simple_editor = new ItemEditor::SimpleEditor();
    stacked_editor->addWidget(simple_editor);
    editors.push_back(simple_editor);

    ItemEditor::VirtualEditor* virtual_editor = new ItemEditor::VirtualEditor();
    stacked_editor->addWidget(virtual_editor);
    editors.push_back(virtual_editor);

    ItemEditor::BundleEditor* bundle_editor = new ItemEditor::BundleEditor(repository);
    stacked_editor->addWidget(bundle_editor);
    editors.push_back(bundle_editor);

    if (subject != nullptr) {
        ItemEditor::ItemInjector item_injector(
            *web_page_editor,
            *simple_editor,
            *virtual_editor,
            *bundle_editor
        );
        subject->accept(item_injector);
    }
    showType(type_input->currentIndex());

    vbox->addStretch();

    QHBoxLayout* actions = new QHBoxLayout();
    actions->setObjectName("actions");
    actions->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(actions);

    actions->addStretch();

    QPushButton* apply_button = new QPushButton("Apply");
    apply_button->setObjectName("apply");
    actions->addWidget(apply_button);

    QPushButton* cancel_button = new QPushButton("Cancel");
    cancel_button->setObjectName("cancel");
    actions->addWidget(cancel_button);

    // Connects signals
    connect(select_image_button, &QPushButton::clicked, this, &EditWidget::selectImage);
    connect(type_input, qOverload<int>(&QComboBox::currentIndexChanged), this, &EditWidget::showType);
    connect(apply_button, &QPushButton::clicked, this, &EditWidget::apply);
    connect(cancel_button, &QPushButton::clicked, main_window->getSearchWidget(), &SearchWidget::search);
}

void EditWidget::selectImage() {
    QString path = QFileDialog::getOpenFileName(
        this,
        "Select image",
        "./",
        "Image files (*.jpg *.jpeg *.png)"
    );
    if (path.isEmpty()) {
        return;
    }
    image_input->setText(path);
}

void EditWidget::showType(int index) {
    stacked_editor->setCurrentIndex(index);
}

void EditWidget::apply() {
    int identifier = identifier_input->value();
    QString name = name_input->text();
    QString description = description_input->toPlainText();
    QString image_path = image_input->text();
    ItemEditor::AbstractItemEditor* editor = editors[stacked_editor->currentIndex()];
    Item::AbstractItem* item = editor->create(identifier, name, description, image_path);
    main_window->getRepository()->update(item);
    main_window->reloadData();
    main_window->getSearchWidget()->search();
}

}