#ifndef VIEW_SEARCH_WIDGET_H
#define VIEW_SEARCH_WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>

#include "../Engine/Query.h"

namespace View {

class SearchWidget: public QWidget {
    Q_OBJECT
  private:
    QLineEdit* query_input;
    QLineEdit* filter_input;
    QSpinBox* page_input;
    QSpinBox* page_size;

  public:
    explicit SearchWidget(QWidget* parent = 0);

  signals:
    void search_event(Engine::Query query);

  public slots:
    void search();
    void previousPage();
    void nextPage();
};

}

#endif