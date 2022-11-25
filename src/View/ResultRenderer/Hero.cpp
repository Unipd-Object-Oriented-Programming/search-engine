#include "Hero.h"

namespace View {
namespace ResultRenderer {

Hero::Hero(const unsigned int row_size)
    : row_size(row_size)
{
}

void Hero::render(QGridLayout* grid, Engine::ResultSet& result, QVector<WidgetLookup>* lookup) {
    unsigned int index = 0;
    for (
        std::vector<Engine::ItemDecorator>::const_iterator it = result.getItems().begin();
        it != result.getItems().end();
        it++
    ) {
        QWidget* widget;
        if (index == 0) {
            it->getItem()->accept(teaser);
            widget = teaser.getWidget();
            grid->addWidget(widget, 0, 0, 1, 3);
            lookup->push_back(WidgetLookup(
                it->getItem(),
                widget,
                teaser.getViewButton(),
                teaser.getEditButton(),
                teaser.getDeleteButton()
            ));
        }
        else if (index < 4) {
            it->getItem()->accept(card);
            widget = card.getWidget();
            grid->addWidget(widget, 1, index - 1);
            lookup->push_back(WidgetLookup(
                it->getItem(),
                widget,
                card.getViewButton(),
                card.getEditButton(),
                card.getDeleteButton()
            ));
        }
        else {
            it->getItem()->accept(list_item);
            widget = list_item.getWidget();
            grid->addWidget(widget, index - 2, 0, 1, row_size);
            lookup->push_back(WidgetLookup(
                it->getItem(),
                widget,
                list_item.getViewButton(),
                list_item.getEditButton(),
                list_item.getDeleteButton()
            ));
        }
        index++;
    }
}

}
}