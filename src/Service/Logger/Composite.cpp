#include "Composite.h"

namespace Service {
namespace Logger {

Composite::Composite() {
}

const std::vector<const AbstractLogger*>& Composite::getLoggers() const {
    return loggers;
}

Composite& Composite::add(const AbstractLogger* logger) {
    loggers.push_back(logger);
    return *this;
}

Composite& Composite::clear() {
    loggers.clear();
    return *this;
}

AbstractLogger const &Composite::log(const std::string& message, const Level level) const {
    for (std::vector<const AbstractLogger *>::const_iterator it = loggers.begin(); it != loggers.end(); it++) {
        (*it)->log(message, level);
    }
    return *this;
}

}
}
