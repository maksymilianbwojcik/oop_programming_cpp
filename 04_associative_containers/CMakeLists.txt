cmake_minimum_required(VERSION 3.10)
project(04_associative_containers)

set(HEADERS include/Dummy.h)
set(SOURCES src/Dummy.cpp)

add_library(04_associative_containers_lib ${HEADERS} ${SOURCES})
target_include_directories(04_associative_containers_lib PUBLIC include)

add_executable(04_associative_containers src/main.cpp)
target_link_libraries(04_associative_containers 04_associative_containers_lib)

add_subdirectory(test)