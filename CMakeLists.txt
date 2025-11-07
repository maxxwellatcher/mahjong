cmake_minimum_required(VERSION 3.11)
project(mahjong LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)

file(GLOB_RECURSE src_files ./src/*c* ./src/*.h*)
message(STATUS "===============================SRC FILES=============================")
foreach(file ${src_files})
    message(STATUS ${file})
endforeach()
message(STATUS "===============================SRC FILES=============================")

include_directories(./src/core)

add_executable(mahjong ${src_files})
set_target_properties(mahjong PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
message("executable path: ${CMAKE_SOURCE_DIR}/bin")