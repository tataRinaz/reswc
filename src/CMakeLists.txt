cmake_minimum_required(VERSION 3.23)

find_package(nlohmann_json)

set(_header_files config.hpp config_interface.hpp)
set(_source_files config.cpp)

add_library(${CMAKE_PROJECT_NAME}.core
    ${_source_files}
    ${_header_files})

target_include_directories(${CMAKE_PROJECT_NAME}.core PUBLIC
    ${JSON_INCLUDE_DIRS})
target_link_libraries(${CMAKE_PROJECT_NAME}.core PUBLIC
    nlohmann_json::nlohmann_json)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC
    ${CMAKE_PROJECT_NAME}.core)



