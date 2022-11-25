#include "AbstractLogger.h"

namespace Service {
namespace Logger {

AbstractLogger::~AbstractLogger() {
}

const AbstractLogger& AbstractLogger::debug(const std::string& message) const {
    return log(message, Level::Debug);
}

const AbstractLogger& AbstractLogger::info(const std::string& message) const {
    return log(message, Level::Info);
}

const AbstractLogger& AbstractLogger::warning(const std::string& message) const {
    return log(message, Level::Warning);
}

const AbstractLogger& AbstractLogger::error(const std::string& message) const {
    return log(message, Level::Error);
}


}
}
