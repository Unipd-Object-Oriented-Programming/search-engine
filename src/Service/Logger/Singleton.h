#ifndef SERVICE_LOGGER_SINGLETON_H
#define SERVICE_LOGGER_SINGLETON_H

#include "AbstractLogger.h"

namespace Service {
namespace Logger {

class Singleton {
  private:
    static const AbstractLogger* logger;

    Singleton();
  public:
    static void init(const AbstractLogger* logger);
    static const AbstractLogger& get();
};

}
}

#endif
