#include "BenchIncludes.h"
#include <vector>
#include <Large.h>
#include <random>

void LargeVectorAt(State& state) {

    auto N = state.range(0);
    std::vector<Large> test (N);
    for (auto _ : state)
    {
        DoNotOptimize(test.at(rand()%N));
    }

    state.SetComplexityN(N);
}

BENCHMARK(LargeVectorAt)->RangeMultiplier(2)->Range(1, 32)->Complexity();

void LargeVectorOperator(State& state) {

    auto N = state.range(0);
    std::vector<Large> test(N);
    for (auto _ : state)
    {
        DoNotOptimize(test[rand()%N]);
    }

    state.SetComplexityN(N);
}

BENCHMARK(LargeVectorOperator)->RangeMultiplier(2)->Range(1, 32)->Complexity();

void LargeVectorFront(State& state) {

    auto N = state.range(0);
    std::vector<Large> test(N);
    for (auto _ : state)
    {
        DoNotOptimize(test.front());
    }

    state.SetComplexityN(N);
}

BENCHMARK(LargeVectorFront)->RangeMultiplier(2)->Range(1, 32)->Complexity();

void LargeVectorBack(State& state) {

    auto N = state.range(0);
    std::vector<Large> test (N);
    for (auto _ : state)
    {
        DoNotOptimize(test.back());
    }

    state.SetComplexityN(N);
}

BENCHMARK(LargeVectorBack)->RangeMultiplier(2)->Range(1, 32)->Complexity();

void LargeVectorData(State& state) {

    auto N = state.range(0);
    std::vector<Large> test (N);
    Large a {};
    test[rand()%N] = a;
    for (auto _ : state)
    {
        DoNotOptimize(test.data());
    }

    state.SetComplexityN(N);
}

BENCHMARK(LargeVectorData)->RangeMultiplier(2)->Range(1, 32)->Complexity();

void LargeVectorEmpty(State& state) {

    auto N = state.range(0);
    std::vector<Large> test {(std::size_t) N};

    for (auto _ : state)
    {
        DoNotOptimize(test.empty());
    }

    state.SetComplexityN(N);
}

BENCHMARK(LargeVectorEmpty)->RangeMultiplier(2)->Range(1, 32)->Complexity();

void LargeVectorSize(State& state) {

    auto N = state.range(0);
    std::vector<Large> test {(std::size_t) N};

    for (auto _ : state)
    {
        DoNotOptimize(test.size());
    }

    state.SetComplexityN(N);
}

BENCHMARK(LargeVectorSize)->RangeMultiplier(2)->Range(1, 32)->Complexity();

void LargeVectorMaxSize(State& state) {

    auto N = state.range(0);
    std::vector<Large> test {(std::size_t) N};

    for (auto _ : state)
    {
        DoNotOptimize(test.max_size());
    }

    state.SetComplexityN(N);
}

BENCHMARK(LargeVectorMaxSize)->RangeMultiplier(2)->Range(1, 32)->Complexity();

void LargeVectorReserve(State& state) {

    auto N = state.range(0);
    std::vector<Large> test {};

    for (auto _ : state)
    {
        DoNotOptimize(test);
        test.reserve(N);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(LargeVectorReserve)->RangeMultiplier(2)->Range(1, 32)->Complexity();

void LargeVectorCapacity(State& state) {

    auto N = state.range(0);
    std::vector<Large> test{(std::size_t) N};

    for (auto _ : state)
    {
        DoNotOptimize(test.capacity());
    }

    state.SetComplexityN(N);
}
BENCHMARK(LargeVectorCapacity)->RangeMultiplier(2)->Range(1, 32)->Complexity();

void LargeVectorShrinkToFit(State& state) {

    auto N = state.range(0);
    for (auto _ : state)
    {

        std::vector<Large> test (N);
        test.resize(1);


        DoNotOptimize(test);
        test.shrink_to_fit();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(LargeVectorShrinkToFit)->RangeMultiplier(2)->Range(1,128)->Complexity();

void LargeVectorClear(State& state) {

    auto N = state.range(0);
    Large a[N];
    std::vector<Large> test;

    for (auto _ : state)
    {

        for (int i=0;i<N;++i)
        {
            a[i].data[0] = rand();
            test.push_back(a[i]);
        }

        DoNotOptimize(test);
        test.clear();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(LargeVectorClear)->RangeMultiplier(2)->Range(1, 32)->Complexity();

void LargeVectorInsert(State& state) {

    auto N = state.range(0);
    Large a{};
    std::vector<Large> test{};
    for (auto _ : state)
    {
       // DoNotOptimize(test);
        DoNotOptimize(test.insert(test.begin(), a));
      //  ClobberMemory();

        test.erase(test.begin());

    }

    state.SetComplexityN(N);
}

BENCHMARK(LargeVectorInsert)->RangeMultiplier(2)->Range(1, 32)->Complexity();

void LargeVectorErase(State& state) {
    auto N = state.range(0);
    Large a[10];
    std::vector<Large> test;
    for (int i = 0; i < 10; i++)
    {
        a[i].data[0] = rand();
        test.push_back(a[i]);
    }

    for(auto _ : state)
    {

        auto it = test.begin();
        Large large{};
        large.data[0] = rand();
        test.insert(it, large);


     //   DoNotOptimize(test);
        DoNotOptimize( test.erase(it));
    //    ClobberMemory();

    }

    state.SetComplexityN(N);
}

BENCHMARK(LargeVectorErase)->RangeMultiplier(2)->Range(1, 32)->Complexity();

void LargeVectorPushBack(State& state) {

    auto N = state.range(0);
    Large a{};
    std::vector<Large> test (N);

    for(auto _ : state)
    {
        DoNotOptimize(test);
        test.push_back(a);
        ClobberMemory();


        test.pop_back();

    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeVectorPushBack)->RangeMultiplier(2)->Range(1, 32)->Complexity();

void LargeVectorPopBack(State& state) {

    auto N = state.range(0);
    Large a{};
    std::vector<Large> test (N);

    for(auto _ : state)
    {

        test.push_back(a);

        DoNotOptimize(test);
        test.pop_back();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeVectorPopBack)->RangeMultiplier(2)->Range(1, 32)->Complexity();

void LargeVectorResize(State& state) {

    auto N = state.range(0);
    for(auto _ : state)
    {

        std::vector<Large>test(N);


        DoNotOptimize(test);
        test.resize(rand()%N);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}

BENCHMARK(LargeVectorResize)->RangeMultiplier(2)->Range(1, 32)->Complexity();

void LargeVectorSwap(State& state) {

    auto N = state.range(0);
    Large a[N];
    Large b[N];
    std::vector<Large> test;
    std::vector<Large> test2;
    for (int i = 0; i < N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();

        test.push_back(a[i]);
        test2.push_back(b[i]);
    }

    for(auto _ : state)
    {
     //   DoNotOptimize(test);
        test.swap(test2);
     //   ClobberMemory();
    }
    state.SetComplexityN(N);

}

BENCHMARK(LargeVectorSwap)->RangeMultiplier(2)->Range(1,32)->Complexity();

//at, operator[], front, back, data,
//empty, size, max_size, reserve, capacity, shrink_to_fit,
//clear, insert, erase, push_back, pop_back, resize, swap

//vector, map, unordered_multiset