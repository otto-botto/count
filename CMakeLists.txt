cmake_minimum_required(VERSION 3.29)
project(count)

# Allow the project to work with c and c++.
file(GLOB csources "${PROJECT_SOURCE_DIR}/*.[ch]")
set_property(SOURCE ${csources} PROPERTY CMAKE_C_STANDARD 11)
file(GLOB cppsources "${PROJECT_SOURCE_DIR}/*.cc")
set_property(SOURCE ${cppsources} PROPERTY CMAKE_CXX_STANDARD 14)
set_property(SOURCE ${cppsources} PROPERTY CMAKE_CXX_STANDARD_REQUIRED ON)

# Set up GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

# this library doesn't need a test (exe) and
# thus doesn't need to stitch things together w/ target_link_libraries
add_library(cjson "cJSON.c" "cJSON.h")
add_library(server "server.c" "server.h")

add_library(count "count.c" "count.h")
add_executable(test_count "test_count.cc")
target_link_libraries(test_count GTest::gtest_main count server cjson)

# Each library looks like this.
add_executable(main "main.c")
target_link_libraries(main server count cjson )
