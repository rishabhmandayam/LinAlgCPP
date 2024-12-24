cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include path for headers
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(LINALGCPP
    main.cpp
    src/matrix.cpp
)