cmake_minimum_required(VERSION 3.15)
project(UseCache CXX)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} Containers2d.h Containers2d.cpp main.cpp)

add_executable(Tests main_tests.cpp)

target_link_libraries(Tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(Tests)