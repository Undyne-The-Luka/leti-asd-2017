cmake_minimum_required(VERSION 3.0)
project(sets)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(sets main.cpp sets.cpp)

install(TARGETS sets RUNTIME DESTINATION bin)
