#ifndef SERVICE_LOGGER_STREAM_H
#define SERVICE_LOGGER_STREAM_H

#include <ostream>

#include "AbstractLogger.h"

namespace Service {
namespace Logger {

class Stream: public AbstractLogger {
  private:
    std::ostream& stream;

  public:
    Stream();
    Stream(std::ostream& stream);
    std::ostream& getStream() const;
    virtual const AbstractLogger& log(const std::string& message, const Level level) const;

  private:
    void getDate(char buffer[]) const;
    const char *levelToString(const Level level) const;
};

}
}

#endif
