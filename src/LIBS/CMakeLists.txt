add_library(
  LIBS
  math_operations.cpp
  math_operations.h  
)

target_include_directories(LIBS PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})