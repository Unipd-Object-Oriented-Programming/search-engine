#ifndef VIEW_ITEM_EDITOR_ABSTRACT_ITEM_EDITOR_H
#define VIEW_ITEM_EDITOR_ABSTRACT_ITEM_EDITOR_H

#include <QWidget>
#include <QString>

#include "../../Item/AbstractItem.h"

namespace View {
namespace ItemEditor {

class AbstractItemEditor: public QWidget {
    Q_OBJECT
  public:
    AbstractItemEditor(QWidget* parent = 0);
    virtual ~AbstractItemEditor();
    virtual Item::AbstractItem* create(
        const unsigned int identifier,
        const QString& name,
        const QString& description,
        const QString& image_path
    ) const = 0;
};

}
}

#endif