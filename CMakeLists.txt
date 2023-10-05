cmake_minimum_required(VERSION 3.15)
include(FetchContent)
project(CPPTemplate)

# Set Compiler Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUNICODE -D_UNICODE")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -D_DEBUG")

# Find Packages
FetchContent_Declare(
        DirectX-Headers
        GIT_REPOSITORY https://github.com/microsoft/DirectX-Headers.git
        GIT_TAG v1.4.9
)

FetchContent_MakeAvailable(DirectX-Headers)

find_package(loguru CONFIG REQUIRED)

# Configure Application
set(APP_NAME CPPTemplate)
set(SOURCES
        src/main.cpp
)

add_executable(${APP_NAME} ${SOURCES})
target_precompile_headers(${APP_NAME} PRIVATE src/pch.h)
target_link_libraries(${APP_NAME} PRIVATE DirectX-Headers loguru::loguru)
target_include_directories(${APP_NAME} PRIVATE src)