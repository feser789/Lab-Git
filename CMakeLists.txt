cmake_minimum_required(VERSION 4.3)
project(Lab4OIPZ)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab4OIPZ main.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(UnitTests test/test.cpp main.cpp)
target_compile_definitions(UnitTests PRIVATE main=app_main)
target_link_libraries(UnitTests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(UnitTests)
