#include "config.hpp"

#include <nlohmann/json.hpp>

#include <gtest/gtest.h>

TEST(ConfigTest, ReadIntExistingKey) {
    auto int_json = R"({
                        "int_value": 124
                       })";
    auto json = nlohmann::json::parse(int_json);
    reswc::Config config(json);
    EXPECT_EQ(config.get_int("int_value"), 124);
}

TEST(ConfigTest, ReadStringExistingKey) {
    auto string_json = R"({
                        "string_value": "aboba"
                       })";
    auto json = nlohmann::json::parse(string_json);
    reswc::Config config(json);
    EXPECT_EQ(config.get_string("string_value"), "aboba");
}

TEST(ConfigTest, ReadIntMissingKey) {
    auto int_json = R"({
                        "int_value": 124
                       })";
    auto json = nlohmann::json::parse(int_json);
    reswc::Config config(json);
    EXPECT_THROW(config.get_int("aboba"), std::out_of_range);
}