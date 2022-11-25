#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "../Item/Repository/JsonRepository.h"
#include "../Engine/IEngine.h"
#include "../Engine/Query.h"
#include "SearchWidget.h"
#include "ResultsWidget.h"
#include "ItemRenderer/Full.h"

namespace View {

class MainWindow: public QMainWindow {
    Q_OBJECT
  private:
    bool has_unsaved_changes;
    QAction* create_item;
    QToolBar* toolbar;
    Engine::IEngine& engine;
    Item::Repository::JsonRepository* repository;
    SearchWidget* search_widget;
    QStackedWidget* stacked_widget;
    ResultsWidget* results_widget;
    ItemRenderer::Full full_renderer;
  
  public:
    explicit MainWindow(Engine::IEngine& engine, QWidget *parent = 0);
    Item::Repository::JsonRepository* getRepository();
    Engine::IEngine& getEngine();
    MainWindow& reloadData();
    SearchWidget* getSearchWidget();
  
  private:
    void clearStack();

  public slots:
    void newDataset();
    void openDataset();
    void saveDataset();
    void saveAsDataset();
    void toggleToolbar();
    void showStatus(QString message);
    void search(Engine::Query query);
    void createItem();
    void showItem(const Item::AbstractItem* item);
    void editItem(const Item::AbstractItem* item);
    void deleteItem(const Item::AbstractItem* item);
    void close();
};

}

#endif