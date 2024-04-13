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

add_subdirectory(TESTS)
add_subdirectory(PROFILING)
add_subdirectory(LIBS)


add_custom_target(clean-all
    COMMAND rm -rf ${CMAKE_BINARY_DIR}/*
    COMMENT "Removing build directory"
)
