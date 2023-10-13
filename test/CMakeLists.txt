cmake_minimum_required(VERSION 3.25)
project(test CXX)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(test-main vector_test.cpp ../matrix.hpp)

target_include_directories(test-main PRIVATE .)
target_link_libraries(test-main PRIVATE Catch2::Catch2WithMain)

enable_testing()

add_test(
        NAME TestMain
        COMMAND test-main
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)