#include "SearchWidget.h"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace View {

SearchWidget::SearchWidget(QWidget* parent)
    : QWidget(parent)
{
    // Creates widgets
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QLabel* title_label = new QLabel("Search Engine");
    title_label->setObjectName("title");
    title_label->setAlignment(Qt::AlignHCenter);
    vbox->addWidget(title_label);

    QFormLayout* form = new QFormLayout();
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vbox->addLayout(form);

    query_input = new QLineEdit();
    form->addRow("query", query_input);

    filter_input = new QLineEdit();
    form->addRow("filter", filter_input);

    page_input = new QSpinBox();
    page_input->setMinimum(1);
    page_input->setSingleStep(1);
    page_input->setValue(1);
    form->addRow("page", page_input);

    page_size = new QSpinBox();
    page_size->setMinimum(1);
    page_size->setMaximum(100);
    page_size->setSingleStep(1);
    page_size->setValue(12);
    form->addRow("results/page", page_size);

    QPushButton* search_input = new QPushButton(
        QIcon(QPixmap((":/assets/icons/search.svg"))),
        "Search"
    );
    vbox->addWidget(search_input);

    // Connects signals
    connect(search_input, &QPushButton::clicked, this, &SearchWidget::search);
}

void SearchWidget::search() {
    Engine::Query query(
        query_input->text().toStdString(),
        filter_input->text().toStdString(),
        (page_input->value() - 1) * page_size->value(),
        page_size->value()
    );
    emit search_event(query);
}

void SearchWidget::previousPage() {
    if (page_input->value() > 1) {
        page_input->setValue(page_input->value() - 1);
        search();
    }
}

void SearchWidget::nextPage() {
    page_input->setValue(page_input->value() + 1);
    search();
}

}