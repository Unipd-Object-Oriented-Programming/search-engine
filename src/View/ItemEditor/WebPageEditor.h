#ifndef VIEW_ITEM_EDITOR_WEB_PAGE_H
#define VIEW_ITEM_EDITOR_WEB_PAGE_H

#include <QWidget>
#include <QLineEdit>

#include "AbstractItemEditor.h"

namespace View {
namespace ItemEditor {

class WebPageEditor: public AbstractItemEditor {
  private:
    QLineEdit* url_input;

  public:
    WebPageEditor(QWidget* parent = 0);
    virtual ~WebPageEditor();
    virtual Item::AbstractItem* create(
        const unsigned int identifier,
        const QString& name,
        const QString& description,
        const QString& image_path
    ) const;

    void setValues(const Item::WebPage& web_page);
};

}
}

#endif