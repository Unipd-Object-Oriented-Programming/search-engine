#ifndef VIEW_RESULT_RENDERER_HERO_H
#define VIEW_RESULT_RENDERER_HERO_H

#include "IResultRendererStrategy.h"

#include "../ResultsWidget.h"
#include "../ItemRenderer/ListItem.h"
#include "../ItemRenderer/Card.h"
#include "../ItemRenderer/Teaser.h"

namespace View {
namespace ResultRenderer {

class Hero: public IResultRendererStrategy {
  private:
    const unsigned int row_size;
    ItemRenderer::ListItem list_item;
    ItemRenderer::Card card;
    ItemRenderer::Teaser teaser;

  public:
    Hero(const unsigned int row_size);
    virtual void render(QGridLayout* grid, Engine::ResultSet& result, QVector<WidgetLookup>* lookup);
};

}
}

#endif