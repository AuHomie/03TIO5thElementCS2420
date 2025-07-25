cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(main)
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( APP_EXECUTABLE main )

include_directories( inc )

ADD_EXECUTABLE(main "src/main.cpp")

#ADD_EXECUTABLE( ${APP_EXECUTABLE} "src/main2.cpp"  "src/main.cpp" "")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT ${APP_EXECUTABLE} )

include (CTest)
add_test(${APP_EXECUTABLE}_test ${APP_EXECUTABLE} 1)

find_program(VALGRIND "valgrind")
if(VALGRIND)
	add_custom_target(valgrind
    COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --show-reachable=yes --error-exitcode=1 $<TARGET_FILE:${APP_EXECUTABLE}>)
endif()