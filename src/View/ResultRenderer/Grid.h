#ifndef VIEW_RESULT_RENDERER_GRID_H
#define VIEW_RESULT_RENDERER_GRID_H

#include "IResultRendererStrategy.h"

#include "../ResultsWidget.h"
#include "../ItemRenderer/Card.h"

namespace View {
namespace ResultRenderer {

class Grid: public IResultRendererStrategy {
  private:
    const unsigned int row_size;
    ItemRenderer::Card card;

  public:
    Grid(const unsigned int row_size);
    virtual void render(QGridLayout* grid, Engine::ResultSet& result, QVector<WidgetLookup>* lookup);
};

}
}

#endif