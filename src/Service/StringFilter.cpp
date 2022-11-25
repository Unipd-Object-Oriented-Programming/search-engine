#include "StringFilter.h"

#include <sstream>
#include <iterator>
#include <algorithm>

namespace Service {

std::string StringFilter::lowercase(const std::string& string) const {
    std::string result(string);
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::vector<std::string> StringFilter::split(const std::string& string) const {
    std::istringstream stream(string);
    std::vector<std::string> result(
        std::istream_iterator<std::string>{stream},
        std::istream_iterator<std::string>()
    );
    return result;
}

}