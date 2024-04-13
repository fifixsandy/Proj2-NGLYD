add_executable(stddev stddev.cpp)
target_link_libraries(stddev PRIVATE LIBS)
add_custom_target(profile 
    COMMAND ${CMAKE_COMMAND} --build . --target stddev
    COMMENT "Building stddev program"
    VERBATIM
)