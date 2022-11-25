#include "ListItem.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QPushButton>

#include "../../Item/WebPage.h"
#include "../../Item/Simple.h"
#include "../../Item/Virtual.h"
#include "../../Item/Bundle.h"

namespace View {
namespace ItemRenderer {

ListItem::ListItem()
    : has_controls(true)
{
}

void ListItem::visit(const Item::WebPage& web_page) {
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("list-item-web-page");

    QHBoxLayout* hbox = new QHBoxLayout(widget);
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    QPixmap image_object(web_page.getImagePath().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(96, 96, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image);

    QVBoxLayout* vbox = new QVBoxLayout();
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    hbox->addLayout(vbox);

    QLabel* name = new QLabel(QString::fromStdString(web_page.getName()));
    name->setObjectName("name");
    vbox->addWidget(name);

    QLabel* link = new QLabel(QString::fromStdString("<a href=\"" + web_page.getUrl() + "\">" + web_page.getUrl() + "</a>"));
    link->setObjectName("link");
    link->setWordWrap(false);
    link->setTextFormat(Qt::RichText);
    link->setTextInteractionFlags(Qt::TextInteractionFlag::LinksAccessibleByMouse);
    link->setOpenExternalLinks(true);
    vbox->addWidget(link);

    QHBoxLayout* actions = new QHBoxLayout();
    actions->setAlignment(Qt::AlignRight | Qt::AlignTop);
    vbox->addLayout(actions);

    actions->addStretch();

    view_button = new QPushButton(QIcon(QPixmap(":/assets/icons/search.svg")), "");
    view_button->setObjectName("view-button");
    actions->addWidget(view_button);

    edit_button = new QPushButton(QIcon(QPixmap(":/assets/icons/edit.svg")), "");
    edit_button->setObjectName("edit-button");
    actions->addWidget(edit_button);

    delete_button = new QPushButton(QIcon(QPixmap(":/assets/icons/delete.svg")), "");
    delete_button->setObjectName("delete-button");
    actions->addWidget(delete_button);
}

void ListItem::visit(const Item::Simple& simple) {
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("list-item-simple");

    QHBoxLayout* hbox = new QHBoxLayout(widget);
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    QPixmap image_object(simple.getImagePath().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(96, 96, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image);

    QVBoxLayout* vbox = new QVBoxLayout();
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    hbox->addLayout(vbox);

    QLabel* name = new QLabel(QString::fromStdString(simple.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);

    QLabel* sku = new QLabel(QString::fromStdString("SKU " + simple.getSku()));
    sku->setObjectName("sku");
    vbox->addWidget(sku);

    QHBoxLayout* details = new QHBoxLayout();
    details->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(details);

    QLabel* price = new QLabel("price " + QString::number(simple.getPrice()) + "€");
    price->setObjectName("price");
    details->addWidget(price);

    if (simple.getAvailability() == 0) {
        QLabel* availability = new QLabel("out of stock");
        availability->setObjectName("availability");
        details->addWidget(availability);
    }

    details->addStretch();

    if (has_controls) {
        view_button = new QPushButton(QIcon(QPixmap(":/assets/icons/search.svg")), "");
        view_button->setObjectName("view-button");
        details->addWidget(view_button);

        edit_button = new QPushButton(QIcon(QPixmap(":/assets/icons/edit.svg")), "");
        edit_button->setObjectName("edit-button");
        details->addWidget(edit_button);

        delete_button = new QPushButton(QIcon(QPixmap(":/assets/icons/delete.svg")), "");
        delete_button->setObjectName("delete-button");
        details->addWidget(delete_button);
    }
}

void ListItem::visit(const Item::Virtual& virtual_item) {
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("list-item-virtual");

    QHBoxLayout* hbox = new QHBoxLayout(widget);
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    QPixmap image_object(virtual_item.getImagePath().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(96, 96, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image);

    QVBoxLayout* vbox = new QVBoxLayout();
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    hbox->addLayout(vbox);

    QLabel* name = new QLabel(QString::fromStdString(virtual_item.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);

    QLabel* sku = new QLabel(QString::fromStdString("SKU:" + virtual_item.getSku()));
    sku->setObjectName("sku");
    vbox->addWidget(sku);

    QHBoxLayout* details = new QHBoxLayout();
    details->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(details);

    QLabel* price = new QLabel("price " + QString::number(virtual_item.getPrice()) + "€");
    price->setObjectName("price");
    details->addWidget(price);

    QLabel* availability = new QLabel(virtual_item.getAvailability() > 0 ? "download now" : "out of stock");
    availability->setObjectName("availability");
    details->addWidget(availability);

    details->addStretch();

    if (has_controls) {
        view_button = new QPushButton(QIcon(QPixmap(":/assets/icons/search.svg")), "");
        view_button->setObjectName("view-button");
        details->addWidget(view_button);

        edit_button = new QPushButton(QIcon(QPixmap(":/assets/icons/edit.svg")), "");
        edit_button->setObjectName("edit-button");
        details->addWidget(edit_button);

        delete_button = new QPushButton(QIcon(QPixmap(":/assets/icons/delete.svg")), "");
        delete_button->setObjectName("delete-button");
        details->addWidget(delete_button);
    }
}

void ListItem::visit(const Item::Bundle& bundle) {
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("list-item-bundle");

    QHBoxLayout* hbox = new QHBoxLayout(widget);
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    QPixmap image_object(bundle.getImagePath().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(96, 96, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image);

    QVBoxLayout* vbox = new QVBoxLayout();
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    hbox->addLayout(vbox);

    QLabel* name = new QLabel(QString::fromStdString(bundle.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);

    QLabel* count = new QLabel(QString::number(bundle.getProducts().size()) + QString(" products in this bundle"));
    count->setObjectName("count");
    vbox->addWidget(count);

    QHBoxLayout* details = new QHBoxLayout();
    details->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    vbox->addLayout(details);

    QLabel* price = new QLabel(QString::number(bundle.getPrice()) + "€");
    price->setObjectName("price");
    details->addWidget(price);

    if (bundle.getAvailability() == 0) {
        QLabel* availability = new QLabel("out of stock");
        availability->setObjectName("availability");
        details->addWidget(availability);
    }

    details->addStretch();

    if (has_controls) {
        view_button = new QPushButton(QIcon(QPixmap(":/assets/icons/search.svg")), "");
        view_button->setObjectName("view-button");
        details->addWidget(view_button);

        edit_button = new QPushButton(QIcon(QPixmap(":/assets/icons/edit.svg")), "");
        edit_button->setObjectName("edit-button");
        details->addWidget(edit_button);

        delete_button = new QPushButton(QIcon(QPixmap(":/assets/icons/delete.svg")), "");
        delete_button->setObjectName("delete-button");
        details->addWidget(delete_button);
    }
}

bool ListItem::hasControls() const {
    return has_controls;
}

void ListItem::setHasControls(const bool has_controls) {
    this->has_controls = has_controls;
}

QWidget* ListItem::getWidget() const {
    return widget;
}

QPushButton* ListItem::getViewButton() const {
    return view_button;
}

QPushButton* ListItem::getEditButton() const {
    return edit_button;
}

QPushButton* ListItem::getDeleteButton() const {
    return delete_button;
}

}
}