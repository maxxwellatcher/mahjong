cmake_minimum_required(VERSION 3.19)
project(mahjong LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(project_name mahjong)

file(GLOB_RECURSE src_files ./src/*c* ./src/*.h*)
message(STATUS "===============================SRC FILES=============================")
foreach(file ${src_files})
    message(STATUS ${file})
endforeach()
message(STATUS "===============================SRC FILES=============================")

if(NOT TARGET spdlog)
    # stand-alone build
    find_package(spdlog REQUIRED)
endif()

add_executable(${project_name} ${src_files})
set_target_properties(${project_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
message(STATUS "executable path: ${CMAKE_SOURCE_DIR}/bin")

target_include_directories(${project_name} PRIVATE ${3rd_libs})
target_include_directories(${project_name} PRIVATE ./src/core)
target_include_directories(${project_name} PRIVATE ${3rd_libs}/spdlog/include)

include(${CMAKE_SOURCE_DIR}/install.cmake)