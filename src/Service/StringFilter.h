#ifndef SERVICE_STRING_FILTER_H
#define SERVICE_STRING_FILTER_H

#include <string>
#include <vector>

namespace Service {

class StringFilter {
  public:
    std::string lowercase(const std::string& string) const;
    std::vector<std::string> split(const std::string& string) const;
};

}

#endif