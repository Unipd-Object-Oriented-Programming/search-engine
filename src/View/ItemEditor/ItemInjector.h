#ifndef VIEW_ITEM_EDITOR_ITEM_INJECTOR_H
#define VIEW_ITEM_EDITOR_ITEM_INJECTOR_H

#include "../../Item/IConstVisitor.h"
#include "WebPageEditor.h"
#include "SimpleEditor.h"
#include "VirtualEditor.h"
#include "BundleEditor.h"

namespace View {
namespace ItemEditor {

class ItemInjector: public Item::IConstVisitor {
  private:
    WebPageEditor& web_page_editor;
    SimpleEditor& simple_editor;
    VirtualEditor& virtual_editor;
    BundleEditor& bundle_editor;

  public:
    ItemInjector(
        WebPageEditor& web_page_editor,
        SimpleEditor& simple_editor,
        VirtualEditor& virtual_editor,
        BundleEditor& bundle_editor
    );
    virtual void visit(const Item::WebPage& web_page);
    virtual void visit(const Item::Simple& simple);
    virtual void visit(const Item::Virtual& virtual_item);
    virtual void visit(const Item::Bundle& bundle);
};

}
}

#endif