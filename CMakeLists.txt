cmake_minimum_required(VERSION 3.10)
project(LINALGCPP)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include path for headers
include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(linalg STATIC src/matrix.cpp)

add_executable(linalg_app main.cpp)
target_link_libraries(linalg_app PRIVATE linalg)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(run_matrix_tests tests/test_matrix.cpp)

target_link_libraries(run_matrix_tests
    PRIVATE
        linalg
        gtest
        gtest_main
    )

add_test(NAME MatrixTest COMMAND run_matrix_tests)
