cmake_minimum_required(VERSION 3.16)
project(RagnarokRPG VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(RagnarokRPG ${SOURCES})

target_include_directories(RagnarokRPG PRIVATE
    include
    external
)

if(WIN32)
    target_compile_definitions(RagnarokRPG PRIVATE _WIN32_WINNT=0x0600)
endif()