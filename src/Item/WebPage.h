#ifndef ITEM_WEB_PAGE_H
#define ITEM_WEB_PAGE_H

#include "AbstractItem.h"

namespace Item {

class WebPage: public AbstractItem {
  private:
    std::string url;

  public:
    WebPage(
        const unsigned int identifier,
        const std::string name,
        const std::string description,
        const std::string image_path,
        const std::string url
    );
    const std::string& getUrl() const;
    WebPage& setUrl(const std::string url);
    virtual void accept(IConstVisitor& visitor) const;
    virtual void accept(IVisitor& visitor);
};

}

#endif