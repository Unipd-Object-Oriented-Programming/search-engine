#include "Grid.h"

namespace View {
namespace ResultRenderer {

Grid::Grid(const unsigned int row_size)
    : row_size(row_size)
{
}

void Grid::render(QGridLayout* grid, Engine::ResultSet& result, QVector<WidgetLookup>* lookup) {
    unsigned int index = 0;
    for (
        std::vector<Engine::ItemDecorator>::const_iterator it = result.getItems().begin();
        it != result.getItems().end();
        it++
    ) {
        it->getItem()->accept(card);
        QWidget* widget = card.getWidget();
        grid->addWidget(widget, index / row_size, index % row_size);
        lookup->push_back(WidgetLookup(
            it->getItem(),
            widget,
            card.getViewButton(),
            card.getEditButton(),
            card.getDeleteButton()
        ));
        index++;
    }
}

}
}