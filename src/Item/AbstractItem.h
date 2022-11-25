#ifndef ITEM_ABSTRACT_ITEM_H
#define ITEM_ABSTRACT_ITEM_H

#include <string>

#include "IConstVisitor.h"
#include "IVisitor.h"

namespace Item {

class AbstractItem {
  private:
    const unsigned int identifier;
    std::string name;
    std::string description;
    std::string image_path;
  
  protected:
    AbstractItem(
        const unsigned int identifier,
        const std::string name,
        const std::string description,
        const std::string image_path
    );

  public:
    virtual ~AbstractItem();
    unsigned int getIdentifier() const;
    const std::string& getName() const;
    AbstractItem& setName(const std::string name);
    const std::string& getDescription() const;
    AbstractItem& setDescription(const std::string description);
    const std::string& getImagePath() const;
    AbstractItem& setImagePath(const std::string image_path);
    virtual void accept(IConstVisitor& visitor) const = 0;
    virtual void accept(IVisitor& visitor) = 0;
};

}

#endif