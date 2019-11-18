cmake_minimum_required(VERSION 3.14)
project(01_cmake LANGUAGES CXX)

include_directories(~/googletest/googletest/include)
link_directories(~/googletest/build/lib)
set(PATHTO ~/Documents/"Semestr 5"/OOP/01_cmake/cmake-build-debug/lib01_cmake_lib.a)

add_library(01_cmake_lib STATIC ~/googletest/build/lib/libgtest.a ~/googletest/build/lib/libgtest_main.a)
add_executable(exec main.cpp)
add_executable(exec2 test.cpp)

#set( ExecFileApp main.cpp)
#add_executable( ${ExecFileApp} main.cpp)
#set( ExecFileTest StaticTest )
#add_executable( ${ExecFileTest} main.cpp 01_cmake.h)
target_link_libraries(exec 01_cmake_lib )
target_link_libraries(exec2 01_cmake_lib pthread gtest gtest_main)
set_target_properties(01_cmake_lib PROPERTIES LINKER_LANGUAGE CXX)
#libgtest.a libgtest_main.a