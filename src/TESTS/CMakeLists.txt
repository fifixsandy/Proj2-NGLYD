add_executable(
  mathTest
  mathOperationsTests.cpp
)
target_link_libraries(
  mathTest
  PRIVATE
  GTest::gtest_main
  LIBS
)

include(GoogleTest)
gtest_discover_tests(mathTest)