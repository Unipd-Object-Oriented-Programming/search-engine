#include <iostream>
#include <ctime>

#include "Stream.h"

#define BUFFER_SIZE 64

namespace Service {
namespace Logger {

Stream::Stream()
    : stream(std::cout) {
}

Stream::Stream(std::ostream& stream)
    : stream(stream) {
}

std::ostream& Stream::getStream() const {
    return stream;
}

const AbstractLogger& Stream::log(const std::string& message, const Level level) const {
    char date_buffer[BUFFER_SIZE];
    getDate(date_buffer);
    
    stream << "[" << date_buffer << "]"
        << "[" << levelToString(level) << "]"
        << " " << message
        << std::endl;
    return *this;
}

void Stream::getDate(char buffer[]) const {
    std::time_t now = std::time(0);
    std::tm* current_time = std::localtime(&now);
    strftime(buffer, BUFFER_SIZE, "%Y-%m-%d %H:%M:%S", current_time);
}

const char *Stream::levelToString(const Level level) const {
    switch (level) {
        case Level::Debug:
            return "DEBUG";
        case Level::Info:
            return "INFO";
        case Level::Warning:
            return "WARNING";
        case Level::Error:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}

}
}
