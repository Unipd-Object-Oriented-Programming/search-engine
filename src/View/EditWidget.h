#ifndef VIEW_EDIT_WIDGET_H
#define VIEW_EDIT_WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QPushButton>
#include <QVector>
#include <QLineEdit>
#include <QSpinBox>
#include <QTextEdit>
#include <QStackedLayout>

#include "MainWindow.h"
#include "../Item/AbstractItem.h"
#include "ItemEditor/AbstractItemEditor.h"
#include "../Item/Repository/JsonRepository.h"

namespace View {

class EditWidget: public QWidget {
    Q_OBJECT
  private:
    MainWindow* main_window;
    const Item::AbstractItem* subject;
    QSpinBox* identifier_input;
    QLineEdit* name_input;
    QTextEdit* description_input;
    QLineEdit* image_input;
    QStackedLayout* stacked_editor;
    QVector<ItemEditor::AbstractItemEditor*> editors;

  public:
    EditWidget(
      MainWindow* main_window,
      Item::Repository::JsonRepository* repository,
      const Item::AbstractItem* subject
    );

  public slots:
    void selectImage();
    void showType(int index);
    void apply();
};

}

#endif