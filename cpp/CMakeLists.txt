cmake_minimum_version_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
project(my_stl)

add_library(gtest)

target_include_directories(
    PUBLIC
        "googletest/googletest/lib/gtest"
)

add_executable(unit_tests
    main.cpp
)

target_link_libraries(unit_tests gtest)
