cmake_minimum_required(VERSION 3.10)
project(dispatcher)

# Specify the required C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Fetch all source files
file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

# Make find package look into deps/
set(BOOST_ROOT "${CMAKE_SOURCE_DIR}/deps/boost_1_82_0_installed")

# Find Boost
find_package(Boost 1.82 REQUIRED)

# Include Boost headers
include_directories(${Boost_INCLUDE_DIRS})

# Sources
add_executable(dispatcher ${SOURCES})

