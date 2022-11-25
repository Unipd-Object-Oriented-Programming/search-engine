#ifndef SERVICE_LOGGER_MINIMUM_LEVEL_H
#define SERVICE_LOGGER_MINIMUM_LEVEL_H

#include "MinimumLevel.h"

namespace Service {
namespace Logger {

MinimumLevel::MinimumLevel(const AbstractLogger &logger, const Level minimum_level)
    : logger(logger), minimum_level(minimum_level) {
}

const AbstractLogger& MinimumLevel::getLogger() const {
    return logger;
}

Level MinimumLevel::getMinimumLevel() const {
    return minimum_level;
}

const AbstractLogger& MinimumLevel::log(const std::string& message, const Level level) const {
    if (level >= minimum_level) {
        logger.log(message, level);
    }
    return *this;
}

}
}

#endif
