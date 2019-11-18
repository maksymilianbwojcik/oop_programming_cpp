cmake_minimum_required(VERSION 3.10)
project(05_stl_benchmark)

set(HEADERS include/Dummy.h include/Small.h include/Medium.h include/Large.h)
set(SOURCES src/Dummy.cpp)

add_library(05_stl_benchmark_lib ${HEADERS} ${SOURCES})
target_include_directories(05_stl_benchmark_lib PUBLIC include)

add_executable(05_stl_benchmark src/main.cpp)
target_link_libraries(05_stl_benchmark 05_stl_benchmark_lib)

add_subdirectory(external)
add_subdirectory(test)
add_subdirectory(bench)