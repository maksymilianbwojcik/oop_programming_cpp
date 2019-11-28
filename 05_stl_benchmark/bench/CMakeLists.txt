set(BENCH_HEADERS include/BenchIncludes.h)
set(BENCH_SOURCES src/DummyBench.cpp src/ExampleBench.cpp src/PauseAndResumeBench.cpp src/SmallBench.cpp src/MediumBench.cpp src/LargeBench.cpp src/SmallVector.cpp src/SmallMap.cpp src/SmallMultiset.cpp src/MediumVector.cpp src/MediumMap.cpp src/MediumMultiset.cpp src/LargeVector.cpp src/LargeMap.cpp src/LargeMultiset.cpp)

add_executable(05_stl_benchmark_bench ${BENCH_HEADERS} ${BENCH_SOURCES})
target_include_directories(05_stl_benchmark_bench PUBLIC include)
target_link_libraries(05_stl_benchmark_bench 05_stl_benchmark_lib benchmark benchmark_main pthread)
