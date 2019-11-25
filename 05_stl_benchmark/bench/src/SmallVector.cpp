#include "BenchIncludes.h"
#include <vector>
#include <Small.h>
#include <random>

void VectorAt(State& state) {

    auto N = state.range(0);
    std::vector<Small> test;
    Small a[N];
    for (int i = 0; i < N; ++i)
    {
        a[i].data[0] = rand();
        test.insert(test.begin(), a[i]);
    }
    for (auto _ : state)
    {
        test.at(0);
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorAt)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorOperator(State& state) {

    auto N = state.range(0);
    std::vector<Small> test;
    Small a[N];
    for (int i = 0; i < N; ++i)
    {
        a[i].data[0] = rand();
        test.insert(test.begin(), a[i]);
    }
    for (auto _ : state)
    {
        test[0];
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorOperator)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorFront(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {};
    Small a[N];
    for (int i = 0; i < N; ++i)
    {
        a[i].data[0] = rand();
        test.push_back(a[i]);
    }
    for (auto _ : state)
    {
        test.front();
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorFront)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorBack(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {};
    Small a[N];
    for (int i = 0; i < N; ++i)
    {
        a[i].data[0] = rand();
        test.push_back(a[i]);
    }
    for (auto _ : state)
    {
        test.back();
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorBack)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorData(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {};
    Small a[N];
    for (int i = 0; i < N; ++i)
    {
        a[i].data[0] = rand();
        test.push_back(a[i]);
    }
    for (auto _ : state)
    {
        test.data();
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorData)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorEmpty(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {(std::size_t) N};

    for (auto _ : state)
    {
        test.empty();
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorEmpty)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorSize(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {(std::size_t) N};

    for (auto _ : state)
    {
        test.size();
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorSize)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorMaxSize(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {(std::size_t) N};

    for (auto _ : state)
    {
        test.max_size();
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorMaxSize)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorReserve(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {};

    for (auto _ : state)
    {
        test.reserve(N);
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorReserve)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorCapacity(State& state) {

    auto N = state.range(0);
    std::vector<Small> test{(std::size_t) N};

    for (auto _ : state)
    {
        DoNotOptimize(test.capacity());
    }

    state.SetComplexityN(N);
}
BENCHMARK(VectorCapacity)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorShrinkToFit(State& state) {

    auto N = state.range(0);
    for (auto _ : state)
    {
        state.PauseTiming();
        std::vector<Small> test (N);
        test.resize(1);
        state.ResumeTiming();

        test.shrink_to_fit();
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorShrinkToFit)->RangeMultiplier(2)->Range(1,1024)->Complexity();

void VectorClear(State& state) {

    auto N = state.range(0);
    Small a[N];
    std::vector<Small> test;

    for (auto _ : state)
    {
        state.PauseTiming();
        for (int i=0;i<N;++i)
        {
            a[i].data[0] = rand();
            test.push_back(a[i]);
        }
        state.ResumeTiming();
        test.clear();
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorClear)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorInsert(State& state) {

    auto N = state.range(0);
    Small a{};
    std::vector<Small> test{};
    for (auto _ : state)
    {
        test.insert(test.begin(), a);
        state.PauseTiming();
        test.erase(test.begin());
        state.ResumeTiming();
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorInsert)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorErase(State& state) {
    auto N = state.range(0);
    Small a[10];
    std::vector<Small> test;
    for (int i = 0; i < 10; i++)
    {
        a[i].data[0] = rand();
        test.push_back(a[i]);
    }

    for(auto _ : state)
    {
        state.PauseTiming();
        auto it = test.begin();
        Small small{};
        small.data[0] = rand();
        test.insert(it, small);
        state.ResumeTiming();

        test.erase(it);
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorErase)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorPushBack(State& state) {

    auto N = state.range(0);
    Small a{};
    std::vector<Small> test = {};

    for(auto _ : state)
    {
        test.push_back(a);

        state.PauseTiming();
        test.pop_back();
        state.ResumeTiming();
    }
    state.SetComplexityN(N);
}

BENCHMARK(VectorPushBack)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorPopBack(State& state) {

    auto N = state.range(0);
    Small a{};
    std::vector<Small> test = {};

    for(auto _ : state)
    {
        state.PauseTiming();
        test.push_back(a);
        state.ResumeTiming();
        test.pop_back();
    }
    state.SetComplexityN(N);
}

BENCHMARK(VectorPopBack)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorResize(State& state) {

    auto N = state.range(0);
    for(auto _ : state)
    {
        state.PauseTiming();
        std::vector<Small>test(N);
        state.ResumeTiming();

        test.resize(1);
    }
    state.SetComplexityN(N);
}

BENCHMARK(VectorResize)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorSwap(State& state) {

    auto N = state.range(0);
    Small a[N];
    Small b[N];
    std::vector<Small> test;
    std::vector<Small> test2;
    for (int i = 0; i < N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();

        test.push_back(a[i]);
        test2.push_back(b[i]);
    }

    for(auto _ : state)
    {
        test.swap(test2);
    }
    state.SetComplexityN(N);

}

BENCHMARK(VectorSwap)->RangeMultiplier(2)->Range(1,256)->Complexity();

//at, operator[], front, back, data,
//empty, size, max_size, reserve, capacity, shrink_to_fit,
//clear, insert, erase, push_back, pop_back, resize, swap

//vector, map, unordered_multiset