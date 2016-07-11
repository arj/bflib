cmake_minimum_required(VERSION 2.8)

project(bf)

set (CMAKE_CXX_STANDARD 14)

set (SOURCE
     include/bflib/tree.h
     include/bflib/tree.hpp
)

add_library(${PROJECT_NAME} ${SOURCE})

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:include/bflib>
)

enable_testing()
add_subdirectory(test)
