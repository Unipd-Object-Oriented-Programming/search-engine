#include "TypeSelector.h"

#include "../Item/IConstVisitor.h"

namespace View {

TypeSelector::TypeSelector(QComboBox* combo_box)
    : combo_box(combo_box)
{
}

void TypeSelector::visit(const Item::WebPage& web_page) {
    (void) web_page;
    combo_box->setCurrentText("web page");
}

void TypeSelector::visit(const Item::Simple& simple) {
    (void) simple;
    combo_box->setCurrentText("simple");
}

void TypeSelector::visit(const Item::Virtual& virtual_item) {
    (void) virtual_item;
    combo_box->setCurrentText("virtual");
}

void TypeSelector::visit(const Item::Bundle& bundle) {
    (void) bundle;
    combo_box->setCurrentText("bundle");
}

QComboBox* TypeSelector::getComboBox() {
    return combo_box;
}

TypeSelector& TypeSelector::setComboBox(QComboBox* combo_box) {
    this->combo_box = combo_box;
    return *this;
}

}