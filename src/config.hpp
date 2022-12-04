#pragma once

#include "config_interface.hpp"
#include <nlohmann/json.hpp>

namespace reswc {
class Config : public ConfigurationInterface {
public:
    explicit Config(nlohmann::json config);
    std::string get_string(std::string_view key) override;
    std::int64_t get_int(std::string_view key) override;

private:
    template<typename ValueType>
    ValueType get_value(std::string_view key);

    nlohmann::json config_;
};
 }