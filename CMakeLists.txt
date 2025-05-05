cmake_minimum_required(VERSION 3.16)

# Project configuration
set(PROJECT_NAME Lab_4_Mikolaj_Wrobel)
set(CXX_STANDARD_REQUIRED 20)

# Project declaration
project(${PROJECT_NAME})

# Set C++ standard
set(CMAKE_CXX_STANDARD ${CXX_STANDARD_REQUIRED})

# Add executable target
add_executable(${PROJECT_NAME} main.cpp)