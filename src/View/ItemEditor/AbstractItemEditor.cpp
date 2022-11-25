#include "AbstractItemEditor.h"

#include <QWidget>

namespace View {
namespace ItemEditor {

AbstractItemEditor::AbstractItemEditor(QWidget* parent)
    : QWidget(parent)
{
}

AbstractItemEditor::~AbstractItemEditor() {
}

}
}