cmake_minimum_required(VERSION 3.16)

project(pricer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTING "Build tests" ON)

add_library(pricer
    src/BlackScholesPricer.cpp
)

target_include_directories(pricer
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

if(BUILD_TESTING)
    include(FetchContent)

    FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)

    enable_testing()
    add_subdirectory(tests)
endif()

add_executable(pricer_app src/main.cpp)
target_link_libraries(pricer_app pricer)
