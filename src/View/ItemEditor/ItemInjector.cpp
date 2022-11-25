#include "ItemInjector.h"

namespace View {
namespace ItemEditor {

ItemInjector::ItemInjector (
    WebPageEditor& web_page_editor,
    SimpleEditor& simple_editor,
    VirtualEditor& virtual_editor,
    BundleEditor& bundle_editor
)
    : web_page_editor(web_page_editor), simple_editor(simple_editor),
    virtual_editor(virtual_editor), bundle_editor(bundle_editor)
{
}

void ItemInjector::visit(const Item::WebPage& web_page) {
    web_page_editor.setValues(web_page);
}

void ItemInjector::visit(const Item::Simple& simple) {
    simple_editor.setValues(simple);
}

void ItemInjector::visit(const Item::Virtual& virtual_item) {
    virtual_editor.setValues(virtual_item);
}

void ItemInjector::visit(const Item::Bundle& bundle) {
    bundle_editor.setValues(bundle);
}

}
}