cmake_minimum_required(VERSION 3.18)

project(cpp_practice)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ranges
    ./src/read_csv.cpp
    ./src/ranges.cpp
)

target_include_directories(ranges
    PRIVATE
    ./include
)