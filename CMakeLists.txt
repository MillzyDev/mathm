cmake_minimum_required(VERSION 3.25)
project(mathm CXX)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(test)

install(FILES matrix.hpp vector.hpp DESTINATION include)