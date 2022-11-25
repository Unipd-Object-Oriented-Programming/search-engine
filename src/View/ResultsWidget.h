#ifndef VIEW_RESULTS_WIDGET_H
#define VIEW_RESULTS_WIDGET_H

#include <QVector>
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include "../Engine/Query.h"
#include "../Engine/ResultSet.h"
#include "ResultRenderer/IResultRendererStrategy.h"
#include "WidgetLookup.h"

namespace View {

class ResultsWidget: public QWidget {
    Q_OBJECT
  private:
    QLabel* results_total;
    QPushButton* previous_page;
    QPushButton* next_page;
    QVector<WidgetLookup> lookup;
    QGridLayout* grid;
    ResultRenderer::IResultRendererStrategy* renderer;

  public:
    explicit ResultsWidget(QWidget* parent = 0);
  
  signals:
    void refreshResults();
    void previousPage();
    void nextPage();
    void showItem(const Item::AbstractItem* item);
    void editItem(const Item::AbstractItem* item);
    void deleteItem(const Item::AbstractItem* item);

  public slots:
    void showResults(Engine::Query query, Engine::ResultSet results);
    void setListRenderer();
    void setGridRenderer();
    void setHeroRenderer();
};

}

#endif