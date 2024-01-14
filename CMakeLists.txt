cmake_minimum_required(VERSION 3.1...3.27)
message(STATUS "Using CMake version ${CMAKE_VERSION}")

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(
  LeetCodeManager
  VERSION 1.0
)
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

add_library(build_settings INTERFACE)

target_include_directories(build_settings INTERFACE include)

# include_directories(include/databse)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
