#include <stdexcept>

#include "Singleton.h"

namespace Service {
namespace Logger {

const AbstractLogger* Singleton::logger = nullptr;

Singleton::Singleton() {
}

void Singleton::init(const AbstractLogger* logger) {
	Singleton::logger = logger;
}

const AbstractLogger& Singleton::get() {
    if (logger == nullptr) {
        throw std::runtime_error("Attempting to use logger before initialization");
    }
    return *logger;
}

}
}
