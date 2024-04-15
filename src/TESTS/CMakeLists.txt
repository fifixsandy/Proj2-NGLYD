cmake_minimum_required(VERSION 3.17)
project(calculator)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  mathTest
  mathOperationsTests.cpp
)

add_library(LIBS 
  ../LIBS/math_operations.h
  ../LIBS/math_operations.cpp
)

target_link_libraries(
  mathTest
  PRIVATE
  LIBS
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(mathTest)


