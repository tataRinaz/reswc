#include <iostream>
#include <filesystem>
#include <fstream>

#include <nlohmann/json.hpp>

#include "config.hpp"


nlohmann::json read_config(std::string_view path) {
    std::ifstream config_file;
    config_file.open(path, std::ios_base::in);
    if (!config_file.is_open()) {
        throw std::invalid_argument(std::string("Config file not found at ") + std::string(path));
    }
    return nlohmann::json::parse(config_file);
}

int wmain(int argc, wchar_t** argv) {
    auto dir = std::filesystem::weakly_canonical(std::filesystem::path(argv[0])).parent_path();
    auto config_file = read_config((dir / "config.json").string());
    reswc::Config config(config_file);
    std::cout << config.get_int("int_value");
    return 0;
}