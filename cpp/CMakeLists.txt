cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
project(my_stl)

# Most basic test to make sure the build system is working
add_executable(test.buildtest
    buildtest.cpp
)

# Add the unit test executable
add_executable(unit_tests
    main.cpp
)

target_compile_options(unit_tests PRIVATE
    -Werror
    -Wextra
    -Wall
    -Wfloat-equal
    -Wundef
    -Wpointer-arith
    -Wcast-align
    -Wstrict-prototypes
    -Wwrite-strings
    -Waggregate-return
    -Wswitch-default
    -Wswitch-enum
    -Wconversion
    -Wunreachable-code
    -Winit-self
    -O2
    )

# Declare libraries that are used
add_library(gtest STATIC IMPORTED)

# Specify where the library + library interface headers can be found
set_target_properties(gtest PROPERTIES
    IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/libs/libgtest.a"
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/googletest/googletest/include"
)

# Declare what libraries are a requirement to the executable
target_link_libraries(unit_tests gtest)


