#include "List.h"

namespace View {
namespace ResultRenderer {

void List::render(QGridLayout* grid, Engine::ResultSet& result, QVector<WidgetLookup>* lookup) {
    unsigned int index = 0;
    for (
        std::vector<Engine::ItemDecorator>::const_iterator it = result.getItems().begin();
        it != result.getItems().end();
        it++
    ) {
        it->getItem()->accept(list_item);
        QWidget* widget = list_item.getWidget();
        grid->addWidget(widget, index, 0);
        lookup->push_back(WidgetLookup(
            it->getItem(),
            widget,
            list_item.getViewButton(),
            list_item.getEditButton(),
            list_item.getDeleteButton()
        ));
        index++;
    }
}

}
}