#include <string>
#include <string_view>


#pragma once 

namespace reswc {
class ConfigurationInterface {
public:
    virtual std::string get_string(std::string_view key) = 0;
    virtual std::int64_t get_int(std::string_view key) = 0;
    virtual ~ConfigurationInterface() = default;

};
}