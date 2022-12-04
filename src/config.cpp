#include "config.hpp"

#include <fstream>


namespace reswc {
Config::Config(nlohmann::json config): config_(std::move(config)) {}

std::string Config::get_string(std::string_view key) {
    return get_value<std::string>(key);
}

std::int64_t Config::get_int(std::string_view key) {
    return get_value<std::int64_t>(key);
}

template<typename ValueType>
inline ValueType Config::get_value(std::string_view key) {
    auto element_pos = config_.find(key);
    if (element_pos == config_.end()) {
        throw std::out_of_range(std::string("Element not found: ") + std::string(key));
    }
    return element_pos->get<ValueType>();
}
}