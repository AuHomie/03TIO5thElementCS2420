cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project( MyStarterProject )

set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( APP_EXECUTABLE MyStarterProgram )

set( LIB_NAME classLibrary )
add_library( ${LIB_NAME} STATIC inc/FifthElement.h )

ADD_EXECUTABLE( ${APP_EXECUTABLE} src/FifthElementTester.cpp )
target_include_directories( ${LIB_NAME} PUBLIC inc )

set_target_properties( ${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

TARGET_LINK_LIBRARIES( ${APP_EXECUTABLE} ${LIB_NAME} )

set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT ${APP_EXECUTABLE} )
