#include "WebPageEditor.h"

#include <QFormLayout>

#include "../../Item/WebPage.h"

namespace View {
namespace ItemEditor {

WebPageEditor::WebPageEditor(QWidget* parent)
    : AbstractItemEditor(parent)
{
    QFormLayout* form = new QFormLayout(this);
    form->setObjectName("web-page-form");
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);

    url_input = new QLineEdit();
    url_input->setObjectName("url-input");
    form->addRow("url", url_input);
}

WebPageEditor::~WebPageEditor() {
}

Item::AbstractItem* WebPageEditor::create(
    const unsigned int identifier,
    const QString& name,
    const QString& description,
    const QString& image_path
) const {
    return new Item::WebPage(
        identifier,
        name.toStdString(),
        description.toStdString(),
        image_path.toStdString(),
        url_input->text().toStdString()
    );
}

void WebPageEditor::setValues(const Item::WebPage& web_page) {
    url_input->setText(QString::fromStdString(web_page.getUrl()));
}

}
}