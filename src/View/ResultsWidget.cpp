#include "ResultsWidget.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>

#include "ResultRenderer/List.h"
#include "ResultRenderer/Grid.h"
#include "ResultRenderer/Hero.h"

namespace View {

ResultsWidget::ResultsWidget(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(hbox);

    results_total = new QLabel();
    hbox->addWidget(results_total);

    hbox->addStretch();

    previous_page = new QPushButton(QIcon(QPixmap(":/assets/icons/previous.svg")), "");
    previous_page->setEnabled(false);
    hbox->addWidget(previous_page);

    next_page = new QPushButton(QIcon(QPixmap(":/assets/icons/next.svg")), "");
    next_page->setEnabled(false);
    hbox->addWidget(next_page);

    hbox->addStretch();

    QPushButton* list_layout = new QPushButton(QIcon(QPixmap(":/assets/icons/list.svg")), "");
    hbox->addWidget(list_layout);

    QPushButton* grid_layout = new QPushButton(QIcon(QPixmap(":/assets/icons/grid.svg")), "");
    hbox->addWidget(grid_layout);

    QPushButton* hero_layout = new QPushButton(QIcon(QPixmap(":/assets/icons/hero.svg")), "");
    hbox->addWidget(hero_layout);

    grid = new QGridLayout();
    grid->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    QWidget* container = new QWidget();
    container->setLayout(grid);
    QScrollArea* scroll_area = new QScrollArea();
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(container);
    vbox->addWidget(scroll_area);

    renderer = new ResultRenderer::List();

    // Connects signals
    connect(previous_page, &QPushButton::clicked, this, &ResultsWidget::previousPage);
    connect(next_page, &QPushButton::clicked, this, &ResultsWidget::nextPage);
    connect(list_layout, &QPushButton::clicked, this, &ResultsWidget::setListRenderer);
    connect(grid_layout, &QPushButton::clicked, this, &ResultsWidget::setGridRenderer);
    connect(hero_layout, &QPushButton::clicked, this, &ResultsWidget::setHeroRenderer);
}

void ResultsWidget::showResults(Engine::Query query, Engine::ResultSet results) {
    // Clears previous data
    while (!lookup.isEmpty()) {
        WidgetLookup info = lookup.takeLast();
        delete info.getWidget();
    }

    // Shows new data
    if (results.getTotal() > 0) {
        results_total->setText(QString::number(results.getTotal()) + " results for \"" + QString::fromStdString(query.getText()) + "\":");
    }
    else {
        results_total->setText("No results for \"" + QString::fromStdString(query.getText()) + "\".");
    }    
    previous_page->setEnabled(query.getOffset() > 0);
    next_page->setEnabled(results.getItems().size() == query.getSize());
    renderer->render(grid, results, &lookup);

    // Connects signals
    for (
        QVector<WidgetLookup>::const_iterator it = lookup.begin();
        it != lookup.end();
        it++
    ) {
        if (it->getViewButton()) {
            connect(it->getViewButton(), &QPushButton::clicked, std::bind(&ResultsWidget::showItem, this, it->getItem()));
        }
        if (it->getEditButton()) {
            connect(it->getEditButton(), &QPushButton::clicked, std::bind(&ResultsWidget::editItem, this, it->getItem()));
        }
        if (it->getDeleteButton()) {
            connect(it->getDeleteButton(), &QPushButton::clicked, std::bind(&ResultsWidget::deleteItem, this, it->getItem()));
        }
    }
}

void ResultsWidget::setListRenderer() {
    delete renderer;
    ResultRenderer::List* list = new ResultRenderer::List();
    renderer = list;
    emit refreshResults();
}

void ResultsWidget::setGridRenderer() {
    delete renderer;
    renderer = new ResultRenderer::Grid(3);
    emit refreshResults();
}

void ResultsWidget::setHeroRenderer() {
    delete renderer;
    renderer = new ResultRenderer::Hero(3);
    emit refreshResults();
}

}