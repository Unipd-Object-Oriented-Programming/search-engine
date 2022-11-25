#include <ostream>

#include "AbstractLogger.h"

namespace Service {
namespace Logger {

class MinimumLevel: public AbstractLogger {
  private:
    const AbstractLogger &logger;
    const Level minimum_level;

  public:
    MinimumLevel(const AbstractLogger &logger, const Level minimum_level);
    const AbstractLogger &getLogger() const;
    Level getMinimumLevel() const;
    virtual const AbstractLogger& log(const std::string& message, const Level level) const;
};

}
}
