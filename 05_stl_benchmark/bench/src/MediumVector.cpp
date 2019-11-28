#include "BenchIncludes.h"
#include <vector>
#include <Medium.h>
#include <random>

void MediumVectorAt(State& state) {

    auto N = state.range(0);
    std::vector<Medium> test (N);
    for (auto _ : state)
    {
        DoNotOptimize(test.at(rand()%N));
    }

    state.SetComplexityN(N);
}

BENCHMARK(MediumVectorAt)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void MediumVectorOperator(State& state) {

    auto N = state.range(0);
    std::vector<Medium> test(N);
    for (auto _ : state)
    {
        DoNotOptimize(test[rand()%N]);
    }

    state.SetComplexityN(N);
}

BENCHMARK(MediumVectorOperator)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void MediumVectorFront(State& state) {

    auto N = state.range(0);
    std::vector<Medium> test(N);
    for (auto _ : state)
    {
        DoNotOptimize(test.front());
    }

    state.SetComplexityN(N);
}

BENCHMARK(MediumVectorFront)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void MediumVectorBack(State& state) {

    auto N = state.range(0);
    std::vector<Medium> test (N);
    for (auto _ : state)
    {
        DoNotOptimize(test.back());
    }

    state.SetComplexityN(N);
}

BENCHMARK(MediumVectorBack)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void MediumVectorData(State& state) {

    auto N = state.range(0);
    std::vector<Medium> test (N);
    Medium a {};
    test[rand()%N] = a;
    for (auto _ : state)
    {
        DoNotOptimize(test.data());
    }

    state.SetComplexityN(N);
}

BENCHMARK(MediumVectorData)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void MediumVectorEmpty(State& state) {

    auto N = state.range(0);
    std::vector<Medium> test {(std::size_t) N};

    for (auto _ : state)
    {
        DoNotOptimize(test.empty());
    }

    state.SetComplexityN(N);
}

BENCHMARK(MediumVectorEmpty)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void MediumVectorSize(State& state) {

    auto N = state.range(0);
    std::vector<Medium> test {(std::size_t) N};

    for (auto _ : state)
    {
        DoNotOptimize(test.size());
    }

    state.SetComplexityN(N);
}

BENCHMARK(MediumVectorSize)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void MediumVectorMaxSize(State& state) {

    auto N = state.range(0);
    std::vector<Medium> test {(std::size_t) N};

    for (auto _ : state)
    {
        DoNotOptimize(test.max_size());
    }

    state.SetComplexityN(N);
}

BENCHMARK(MediumVectorMaxSize)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void MediumVectorReserve(State& state) {

    auto N = state.range(0);
    std::vector<Medium> test {};

    for (auto _ : state)
    {
        DoNotOptimize(test);
        test.reserve(N);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(MediumVectorReserve)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void MediumVectorCapacity(State& state) {

    auto N = state.range(0);
    std::vector<Medium> test{(std::size_t) N};

    for (auto _ : state)
    {
        DoNotOptimize(test.capacity());
    }

    state.SetComplexityN(N);
}
BENCHMARK(MediumVectorCapacity)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void MediumVectorShrinkToFit(State& state) {

    auto N = state.range(0);
    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<Medium> test (N);
        test.resize(1);
        state.ResumeTiming();

        DoNotOptimize(test);
        test.shrink_to_fit();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(MediumVectorShrinkToFit)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void MediumVectorClear(State& state) {

    auto N = state.range(0);
    Medium a[N];
    std::vector<Medium> test;

    for (auto _ : state)
    {
        state.PauseTiming();
        for (int i=0;i<N;++i)
        {
            a[i].data[0] = rand();
            test.push_back(a[i]);
        }
        state.ResumeTiming();
        DoNotOptimize(test);
        test.clear();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(MediumVectorClear)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void MediumVectorInsert(State& state) {

    auto N = state.range(0);
    Medium a{};
    std::vector<Medium> test{};
    for (auto _ : state)
    {
        DoNotOptimize(test);
        test.insert(test.begin(), a);
        ClobberMemory();
        state.PauseTiming();
        test.erase(test.begin());
        state.ResumeTiming();
    }

    state.SetComplexityN(N);
}

BENCHMARK(MediumVectorInsert)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void MediumVectorErase(State& state) {
    auto N = state.range(0);
    Medium a[10];
    std::vector<Medium> test;
    for (int i = 0; i < 10; i++)
    {
        a[i].data[0] = rand();
        test.push_back(a[i]);
    }

    for(auto _ : state)
    {
        state.PauseTiming();
        auto it = test.begin();
        Medium medium{};
        medium.data[0] = rand();
        test.insert(it, medium);
        state.ResumeTiming();

        DoNotOptimize(test);
        test.erase(it);
        ClobberMemory();

    }

    state.SetComplexityN(N);
}

BENCHMARK(MediumVectorErase)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void MediumVectorPushBack(State& state) {

    auto N = state.range(0);
    Medium a{};
    std::vector<Medium> test (N);

    for(auto _ : state)
    {
        DoNotOptimize(test);
        test.push_back(a);
        ClobberMemory();

        state.PauseTiming();
        test.pop_back();
        state.ResumeTiming();
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumVectorPushBack)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void MediumVectorPopBack(State& state) {

    auto N = state.range(0);
    Medium a{};
    std::vector<Medium> test (N);

    for(auto _ : state)
    {
        state.PauseTiming();
        test.push_back(a);
        state.ResumeTiming();
        DoNotOptimize(test);
        test.pop_back();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumVectorPopBack)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void MediumVectorResize(State& state) {

    auto N = state.range(0);
    for(auto _ : state)
    {
        state.PauseTiming();
        std::vector<Medium>test(N);
        state.ResumeTiming();

        DoNotOptimize(test);
        test.resize(rand()%N);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}

BENCHMARK(MediumVectorResize)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void MediumVectorSwap(State& state) {

    auto N = state.range(0);
    Medium a[N];
    Medium b[N];
    std::vector<Medium> test;
    std::vector<Medium> test2;
    for (int i = 0; i < N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();

        test.push_back(a[i]);
        test2.push_back(b[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(test);
        test.swap(test2);
        ClobberMemory();
    }
    state.SetComplexityN(N);

}

BENCHMARK(MediumVectorSwap)->RangeMultiplier(2)->Range(1,256)->Complexity();

//at, operator[], front, back, data,
//empty, size, max_size, reserve, capacity, shrink_to_fit,
//clear, insert, erase, push_back, pop_back, resize, swap

//vector, map, unordered_multiset