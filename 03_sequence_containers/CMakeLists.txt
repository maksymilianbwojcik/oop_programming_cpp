cmake_minimum_required(VERSION 3.10)
project(03_sequence_containers)

set(HEADERS include/Dummy.h)
set(SOURCES src/Dummy.cpp)

add_library(03_sequence_containers_lib ${HEADERS} ${SOURCES})
target_include_directories(03_sequence_containers_lib PUBLIC include)

add_executable(03_sequence_containers src/main.cpp)
target_link_libraries(03_sequence_containers 03_sequence_containers_lib)

add_subdirectory(test)