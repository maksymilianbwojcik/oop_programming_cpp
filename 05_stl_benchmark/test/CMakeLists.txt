set(TEST_HEADERS include/TestIncludes.h)
set(TEST_SOURCES src/DummyTest.cpp src/SmallTest.cpp src/MediumTest.cpp src/LargeTest.cpp)

add_executable(05_stl_benchmark_test ${TEST_HEADERS} ${TEST_SOURCES})
target_include_directories(05_stl_benchmark_test PUBLIC include)
target_link_libraries(05_stl_benchmark_test 05_stl_benchmark_lib gtest gtest_main pthread)
