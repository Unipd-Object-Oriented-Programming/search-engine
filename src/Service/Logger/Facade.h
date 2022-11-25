#ifndef SERVICE_LOGGER_FACADE_H
#define SERVICE_LOGGER_FACADE_H

#include <string>
#include <fstream>

#include "AbstractLogger.h"
#include "Level.h"
#include "Stream.h"
#include "MinimumLevel.h"
#include "Composite.h"

namespace Service {
namespace Logger {

class Facade {
  public:
    const Level DEFAULT_CONSOLE_MINIMUM_LEVEL = Level::Debug;
    const Level DEFAULT_FILE_MINIMUM_LEVEL = Level::Warning;

  private:
    const Stream console_logger;
    const MinimumLevel console_filtered_logger;
    std::ofstream file_stream;
    const Stream file_logger;
    const MinimumLevel file_filtered_logger;
    Composite logger;

  public:
    Facade(const std::string& file_path);
    Facade(
        const std::string& file_path,
        const Level console_minimum_level,
        const Level file_minimum_level
    );
};

}
}

#endif