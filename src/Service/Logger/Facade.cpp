#include "Facade.h"

#include "Singleton.h"

namespace Service {
namespace Logger {

Facade::Facade(const std::string& file_path)
    :
    console_filtered_logger(console_logger, DEFAULT_CONSOLE_MINIMUM_LEVEL),
    file_stream(file_path),
    file_logger(file_stream),
    file_filtered_logger(file_logger, DEFAULT_FILE_MINIMUM_LEVEL)
{
    logger
        .add(&console_filtered_logger)
        .add(&file_filtered_logger)
    ;
    Singleton::init(&logger);
}

Facade::Facade(
    const std::string& file_path,
    const Level console_minimum_level,
    const Level file_minimum_level
)
    :
    console_filtered_logger(console_logger, console_minimum_level),
    file_stream(file_path),
    file_logger(file_stream),
    file_filtered_logger(file_logger, file_minimum_level)
{
    logger
        .add(&console_filtered_logger)
        .add(&file_filtered_logger)
    ;
    Singleton::init(&logger);
}

}
}