cmake_minimum_required(VERSION 3.10)
project(TemplateShapeExample)

set(CXX_STANDARD 17)
set(INTERFACE_HEADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

set(CMAKE_CXX_STANDARD ${CXX_STANDARD})
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(ShapeLibrary INTERFACE)

target_include_directories(ShapeLibrary INTERFACE ${INTERFACE_HEADER_DIR})

target_compile_features(ShapeLibrary INTERFACE cxx_std_${CXX_STANDARD})
