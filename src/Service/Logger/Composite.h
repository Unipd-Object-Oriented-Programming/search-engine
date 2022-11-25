#ifndef SERVICE_LOGGER_COMPOSITE_H
#define SERVICE_LOGGER_COMPOSITE_H

#include <vector>

#include "AbstractLogger.h"

namespace Service {
namespace Logger {

class Composite: public AbstractLogger {
  private:
    std::vector<const AbstractLogger*> loggers;

  public:
    Composite();
    const std::vector<const AbstractLogger*>& getLoggers() const;
    Composite& add(const AbstractLogger* logger);
    Composite& clear();
    virtual const AbstractLogger& log(const std::string& message, const Level level) const;
};

}
}

#endif
