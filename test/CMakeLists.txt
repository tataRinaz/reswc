cmake_minimum_required(VERSION 3.23)

find_package(GTest REQUIRED)
find_package(nlohmann_json)

enable_testing()

set(_target_name ${PROJECT_NAME}.tests)

add_executable(${_target_name}
    config_tests.cpp)

target_include_directories(${_target_name} PUBLIC
    ${GTEST_INCLUDE_DIRS}
    ${JSON_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(${_target_name} PUBLIC
    GTest::gtest
    GTest::gtest_main
    GTest::gmock
    GTest::gmock_main
    nlohmann_json::nlohmann_json
    ${CMAKE_PROJECT_NAME}.core)

add_test(
    NAME ${_target_name}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    COMMAND ${_target_name}.exe)