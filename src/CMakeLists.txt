cmake_minimum_required(VERSION 3.23)

file(GLOB _header_files ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
file(GLOB _source_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${CMAKE_PROJECT_NAME}
    ${_source_files}
    ${_header_files})
