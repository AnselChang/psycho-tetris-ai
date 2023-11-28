cmake_minimum_required(VERSION 3.10)   # Set the minimum required version of CMake
project(Psycho)                     # Define the project name

set(CMAKE_CXX_STANDARD 17)             # Use C++17 standard
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)                  # Add the source directory
include_directories(${CMAKE_SOURCE_DIR}/include) # Include the header files

enable_testing()                       # Enable testing (if you have tests)
