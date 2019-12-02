set(TEST_HEADERS include/TestIncludes.h)
set(TEST_SOURCES src/UniverseTest.cpp)

add_executable(08_fake_mock_or_stub_test ${TEST_HEADERS} ${TEST_SOURCES})
target_include_directories(08_fake_mock_or_stub_test PUBLIC include)
target_link_libraries(08_fake_mock_or_stub_test 08_fake_mock_or_stub_lib gmock gmock_main pthread)
