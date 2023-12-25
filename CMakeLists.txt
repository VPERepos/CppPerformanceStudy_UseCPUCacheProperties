cmake_minimum_required(VERSION 3.15)
project(UseCache CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CONFIGURATION_TYPES "Release")

enable_testing()

find_package(GTest REQUIRED)

add_library(ContainersStatic Containers2d.cpp)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} GTest::gtest ContainersStatic)

add_executable(Tests main_tests.cpp)

target_link_libraries(Tests GTest::gtest_main ContainersStatic)

include(GoogleTest)
gtest_discover_tests(Tests)