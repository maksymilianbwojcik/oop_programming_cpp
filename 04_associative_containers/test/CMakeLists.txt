set(GOOGLETEST ../../googletest)

include_directories(${GOOGLETEST}/googletest/include)
link_directories(${GOOGLETEST}/build/lib)

set(TEST_HEADERS include/TestIncludes.h)
set(TEST_SOURCES src/DummyTest.cpp src/CollectionsTest.cpp)

add_executable(04_associative_containers_test ${TEST_HEADERS} ${TEST_SOURCES})
target_include_directories(04_associative_containers_test PUBLIC include)
target_link_libraries(04_associative_containers_test 04_associative_containers_lib gtest gtest_main pthread)
