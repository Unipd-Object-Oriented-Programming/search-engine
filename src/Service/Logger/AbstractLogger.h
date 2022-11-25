#ifndef SERVICE_LOGGER_ABSTRACT_LOGGER_H
#define SERVICE_LOGGER_ABSTRACT_LOGGER_H

#include <string>
#include "Level.h"

namespace Service {
namespace Logger {

class AbstractLogger {
  public:
    virtual ~AbstractLogger();
    virtual const AbstractLogger& log(const std::string& message, const Level level) const = 0;
    const AbstractLogger& debug(const std::string& message) const;
    const AbstractLogger& info(const std::string& message) const;
    const AbstractLogger& warning(const std::string& message) const;
    const AbstractLogger& error(const std::string& message) const;
};

}
}

#endif
