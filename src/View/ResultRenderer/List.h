#ifndef VIEW_RESULT_RENDERER_LIST_H
#define VIEW_RESULT_RENDERER_LIST_H

#include "IResultRendererStrategy.h"

#include "../ResultsWidget.h"
#include "../ItemRenderer/ListItem.h"

namespace View {
namespace ResultRenderer {

class List: public IResultRendererStrategy {
  private:
    ItemRenderer::ListItem list_item;

  public:
    virtual void render(QGridLayout* grid, Engine::ResultSet& result, QVector<WidgetLookup>* lookup);
};

}
}

#endif