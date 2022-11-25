#include "Card.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>

#include "../../Item/WebPage.h"
#include "../../Item/Simple.h"
#include "../../Item/Virtual.h"
#include "../../Item/Bundle.h"

namespace View {
namespace ItemRenderer {

void Card::visit(const Item::WebPage& web_page) {
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("card-web-page");

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignCenter);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    vbox->addLayout(hbox);

    QPixmap image_object(web_page.getImagePath().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(256, 256, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image, 0, Qt::AlignHCenter);

    QVBoxLayout* actions = new QVBoxLayout();
    actions->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    hbox->addLayout(actions);

    view_button = new QPushButton(QIcon(QPixmap(":/assets/icons/search.svg")), "");
    view_button->setObjectName("view-button");
    actions->addWidget(view_button);

    edit_button = new QPushButton(QIcon(QPixmap(":/assets/icons/edit.svg")), "");
    edit_button->setObjectName("edit-button");
    actions->addWidget(edit_button);

    delete_button = new QPushButton(QIcon(QPixmap(":/assets/icons/delete.svg")), "");
    delete_button->setObjectName("delete-button");
    actions->addWidget(delete_button);

    QLabel* link = new QLabel(QString::fromStdString("<a href=\"" + web_page.getUrl() + "\">" + web_page.getName() + "</a>"));
    link->setObjectName("link");
    link->setWordWrap(false);
    link->setTextFormat(Qt::RichText);
    link->setTextInteractionFlags(Qt::TextInteractionFlag::LinksAccessibleByMouse);
    link->setOpenExternalLinks(true);
    vbox->addWidget(link);
}

void Card::visit(const Item::Simple& simple) {
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("card-simple");

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignCenter);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    vbox->addLayout(hbox);

    QPixmap image_object(simple.getImagePath().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(256, 256, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image, 0, Qt::AlignHCenter);

    QVBoxLayout* actions = new QVBoxLayout();
    actions->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    hbox->addLayout(actions);

    view_button = new QPushButton(QIcon(QPixmap(":/assets/icons/search.svg")), "");
    view_button->setObjectName("view-button");
    actions->addWidget(view_button);

    edit_button = new QPushButton(QIcon(QPixmap(":/assets/icons/edit.svg")), "");
    edit_button->setObjectName("edit-button");
    actions->addWidget(edit_button);

    delete_button = new QPushButton(QIcon(QPixmap(":/assets/icons/delete.svg")), "");
    delete_button->setObjectName("delete-button");
    actions->addWidget(delete_button);

    QLabel* name = new QLabel(QString::fromStdString(simple.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);

    QLabel* sku = new QLabel(QString::fromStdString("SKU " + simple.getSku()));
    sku->setObjectName("sku");
    vbox->addWidget(sku);

    QHBoxLayout* details = new QHBoxLayout();
    details->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    vbox->addLayout(details);

    QLabel* price = new QLabel("price " + QString::number(simple.getPrice()) + "€");
    price->setObjectName("price");
    details->addWidget(price);

    details->addStretch();

    QLabel* availability = new QLabel(QString::number(simple.getAvailability()) + " available");
    availability->setObjectName("availability");
    details->addWidget(availability);
}

void Card::visit(const Item::Virtual& virtual_item) {
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("card-virtual");

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignCenter);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    vbox->addLayout(hbox);

    QPixmap image_object(virtual_item.getImagePath().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(256, 256, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image, 0, Qt::AlignHCenter);

    QVBoxLayout* actions = new QVBoxLayout();
    actions->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    hbox->addLayout(actions);

    view_button = new QPushButton(QIcon(QPixmap(":/assets/icons/search.svg")), "");
    view_button->setObjectName("view-button");
    actions->addWidget(view_button);

    edit_button = new QPushButton(QIcon(QPixmap(":/assets/icons/edit.svg")), "");
    edit_button->setObjectName("edit-button");
    actions->addWidget(edit_button);

    delete_button = new QPushButton(QIcon(QPixmap(":/assets/icons/delete.svg")), "");
    delete_button->setObjectName("delete-button");
    actions->addWidget(delete_button);

    QLabel* name = new QLabel(QString::fromStdString(virtual_item.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);

    QLabel* sku = new QLabel(QString::fromStdString("SKU " + virtual_item.getSku()));
    sku->setObjectName("sku");
    vbox->addWidget(sku);

    QHBoxLayout* details = new QHBoxLayout();
    details->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    vbox->addLayout(details);

    QLabel* price = new QLabel("price " + QString::number(virtual_item.getPrice()) + "€");
    price->setObjectName("price");
    details->addWidget(price);

    details->addStretch();

    QLabel* availability = new QLabel(QString::number(virtual_item.getAvailability()) + " downloadable");
    availability->setObjectName("availability");
    details->addWidget(availability);
}

void Card::visit(const Item::Bundle& bundle) {
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;
    widget = new QWidget();
    widget->setObjectName("card-bundle");

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignCenter);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    vbox->addLayout(hbox);

    QPixmap image_object(bundle.getImagePath().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(256, 256, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image, 0, Qt::AlignHCenter);

    QVBoxLayout* actions = new QVBoxLayout();
    actions->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    hbox->addLayout(actions);

    view_button = new QPushButton(QIcon(QPixmap(":/assets/icons/search.svg")), "");
    view_button->setObjectName("view-button");
    actions->addWidget(view_button);

    edit_button = new QPushButton(QIcon(QPixmap(":/assets/icons/edit.svg")), "");
    edit_button->setObjectName("edit-button");
    actions->addWidget(edit_button);

    delete_button = new QPushButton(QIcon(QPixmap(":/assets/icons/delete.svg")), "");
    delete_button->setObjectName("delete-button");
    actions->addWidget(delete_button);

    QLabel* name = new QLabel(QString::fromStdString(bundle.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);

    QLabel* count = new QLabel(QString::number(bundle.getProducts().size()) + " products in this bundle");
    count->setObjectName("count");
    vbox->addWidget(count);

    QHBoxLayout* details = new QHBoxLayout();
    details->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    vbox->addLayout(details);

    QLabel* price = new QLabel("price " + QString::number(bundle.getPrice()) + "€");
    price->setObjectName("price");
    details->addWidget(price);

    details->addStretch();

    QLabel* availability = new QLabel(QString::number(bundle.getAvailability()) + " available");
    availability->setObjectName("availability");
    details->addWidget(availability);
}

QWidget* Card::getWidget() const {
    return widget;
}

QPushButton* Card::getViewButton() const {
    return view_button;
}

QPushButton* Card::getEditButton() const {
    return edit_button;
}

QPushButton* Card::getDeleteButton() const {
    return delete_button;
}

}
}