#include "WebPage.h"

namespace Item {

WebPage::WebPage(
    const unsigned int identifier,
    const std::string name,
    const std::string description,
    const std::string image_path,
    const std::string url
)
    : AbstractItem(identifier, name, description, image_path),
    url(url)
{
}

const std::string& WebPage::getUrl() const {
    return url;
}

WebPage& WebPage::setUrl(const std::string url) {
    this->url = url;
    return *this;
}

void WebPage::accept(IConstVisitor& visitor) const {
    visitor.visit(*this);
}

void WebPage::accept(IVisitor& visitor) {
    visitor.visit(*this);
}

}