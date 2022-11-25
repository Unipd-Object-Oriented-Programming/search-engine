#include "Full.h"

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

void Full::visit(const Item::WebPage& web_page) {
    widget = new QWidget();
    widget->setObjectName("full-web-page");
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* name = new QLabel(QString::fromStdString(web_page.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(hbox);

    QPixmap image_object(web_page.getImagePath().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(512, 512, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image);

    QVBoxLayout* details = new QVBoxLayout();
    details->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    hbox->addLayout(details);

    QLabel* link = new QLabel(QString::fromStdString("<a href=\"" + web_page.getUrl() + "\">" + web_page.getUrl() + "</a>"));
    link->setObjectName("link");
    link->setWordWrap(false);
    link->setTextFormat(Qt::RichText);
    link->setTextInteractionFlags(Qt::TextInteractionFlag::LinksAccessibleByMouse);
    link->setOpenExternalLinks(true);
    details->addWidget(link);

    QLabel* description = new QLabel(QString::fromStdString(web_page.getDescription()));
    description->setObjectName("description");
    description->setWordWrap(true);
    details->addWidget(description);
}

void Full::visit(const Item::Simple& simple) {
    widget = new QWidget();
    widget->setObjectName("full-simple");
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* name = new QLabel(QString::fromStdString(simple.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(hbox);

    QPixmap image_object(simple.getImagePath().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(512, 512, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image);

    QVBoxLayout* details = new QVBoxLayout();
    details->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    hbox->addLayout(details);

    QLabel* sku = new QLabel(QString::fromStdString(simple.getSku()));
    sku->setObjectName("sku");
    details->addWidget(sku);

    QLabel* description = new QLabel(QString::fromStdString(simple.getDescription()));
    description->setObjectName("description");
    description->setWordWrap(true);
    details->addWidget(description);

    QLabel* price = new QLabel("Price: " + QString::number(simple.getPrice()) + "€");
    price->setObjectName("price");
    details->addWidget(price);

    QLabel* availability = new QLabel("Available: " + QString::number(simple.getAvailability()));
    availability->setObjectName("availability");
    details->addWidget(availability);
}

void Full::visit(const Item::Virtual& virtual_item) {
    widget = new QWidget();
    widget->setObjectName("full-virtual");
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* name = new QLabel(QString::fromStdString(virtual_item.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(hbox);

    QPixmap image_object(virtual_item.getImagePath().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(512, 512, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image);

    QVBoxLayout* details = new QVBoxLayout();
    details->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    hbox->addLayout(details);

    QLabel* sku = new QLabel(QString::fromStdString(virtual_item.getSku()));
    sku->setObjectName("sku");
    details->addWidget(sku);

    QLabel* description = new QLabel(QString::fromStdString(virtual_item.getDescription()));
    description->setObjectName("description");
    description->setWordWrap(true);
    details->addWidget(description);

    QLabel* price = new QLabel("Price: " + QString::number(virtual_item.getPrice()) + "€");
    price->setObjectName("price");
    details->addWidget(price);

    QLabel* availability = new QLabel("Downloadable: " + QString::number(virtual_item.getAvailability()));
    availability->setObjectName("availability");
    details->addWidget(availability);
}

void Full::visit(const Item::Bundle& bundle) {
    widget = new QWidget();
    widget->setObjectName("full-bundle");
    view_button = nullptr;
    edit_button = nullptr;
    delete_button = nullptr;

    QVBoxLayout* vbox = new QVBoxLayout(widget);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* name = new QLabel(QString::fromStdString(bundle.getName()));
    name->setObjectName("name");
    name->setWordWrap(true);
    vbox->addWidget(name);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(hbox);

    QPixmap image_object(bundle.getImagePath().c_str());
    if (!image_object) {
        image_object = QPixmap(":/assets/images/placeholder.svg");
    }
    QLabel* image = new QLabel();
    image->setPixmap(image_object.scaled(512, 512, Qt::AspectRatioMode::KeepAspectRatio));
    hbox->addWidget(image, 0, Qt::AlignTop);

    QVBoxLayout* details = new QVBoxLayout();
    details->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    hbox->addLayout(details);

    QLabel* sku = new QLabel(QString::fromStdString(bundle.getSku()));
    sku->setObjectName("sku");
    details->addWidget(sku);

    QLabel* description = new QLabel(QString::fromStdString(bundle.getDescription()));
    description->setObjectName("description");
    description->setWordWrap(true);
    details->addWidget(description);

    QLabel* products = new QLabel("Products in this bundle:");
    products->setObjectName("products");
    details->addWidget(products);

    std::vector<const Item::AbstractProduct *> items = bundle.getProducts();
    for (
        std::vector<const Item::AbstractProduct *>::const_iterator it = items.begin();
        it != items.end();
        it++
    ) {
        list_item.setHasControls(false);
        (*it)->accept(list_item);
        details->addWidget(list_item.getWidget());
    }
}

QWidget* Full::getWidget() const {
    return widget;
}

QPushButton* Full::getViewButton() const {
    return view_button;
}

QPushButton* Full::getEditButton() const {
    return edit_button;
}

QPushButton* Full::getDeleteButton() const {
    return delete_button;
};

}
}