@echo OFF

@set build_type=%1

@set BUILD_DIR="%~dp0\cmake_build"
IF exist %BUILD_DIR% (
    rm -rf %BUILD_DIR%
)

mkdir %BUILD_DIR%
pushd %BUILD_DIR%

conan install .. --build=missing -s build_type=%build_type%
cmake .. -G "Visual Studio 16" -A x64 -DCONAN_CMAKE_SILENT_OUTPUT=ON -DCMAKE_TOOLCHAIN_FILE="conan_toolchain.cmake" -DCMAKE_BUILD_TYPE=%build_type%

popd %BUILD_DIR%

@echo ON