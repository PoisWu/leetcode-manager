cmake_minimum_required(VERSION 3.1...3.27)
message(STATUS "Using CMake version ${CMAKE_VERSION}")

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(
  LeetCodeManager
  VERSION 1.0
)

set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)


set(SOURCE_DIR src)
set(SOURCE main.cpp)
set(LIBRARIES_DIR libs)
set(LIBRARIES curlpp)



add_library(MyLibExample simple_lib.cpp simple_lib.hpp)

add_executable(${PROJECT_NAME} ${FOO_SOURCE})

foreach(LIBRARY ${FOO_LIBRARIES})
    add_subdirectory("${FOO_LIBRARIES_DIR}/${LIBRARY}")
endforeach(LIBRARY)
target_link_libraries(${FOO_PROJECT_NAME} ${FOO_LIBRARIES})

# Link each target with other targets or add options, etc.

# Adding something we can run - Output name matches target name
add_executable(${PROJECT_NAME} simple_example.cpp)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# Make sure you link your targets with this command. It can also link libraries and
# even flags, so linking a target that does not exist will not give a configure-time error.

