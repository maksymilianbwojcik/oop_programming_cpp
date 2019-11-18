#include "BenchIncludes.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <Small.h>

//at, operator[], front, back, data,
//empty, size, max_size, reserve, capacity, shrink_to_fit,
//clear, insert, erase, push_back, pop_back, resize, swap


void Vector(State& state) {

    auto N = state.range(0);
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            std::vector<Small> test;
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(Vector)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorAt(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {1};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            test.at(0);
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorAt)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorOperator(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {1};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            test[0] = {3};
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorOperator)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorFront(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {1};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            test.front();
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorFront)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorBack(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {1};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            test.back();
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorBack)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorEmpty(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {1};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            test.empty();
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorEmpty)->RangeMultiplier(2)->Range(1, 256)->Complexity();


void VectorData(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {1};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            test.data();
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorData)->RangeMultiplier(2)->Range(1, 256)->Complexity();


void VectorSize(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {1};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            test.size();
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorSize)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorMaxSize(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {1};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            test.max_size();
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorMaxSize)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorReserve(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {1};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            test.reserve(2);
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorReserve)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorCapacity(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {1};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            test.capacity();
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorCapacity)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorShrinkToFit(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {1};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            test.shrink_to_fit();
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorShrinkToFit)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void VectorClear(State& state) {

    auto N = state.range(0);
    std::vector<Small> test {1};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            test.clear();
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(VectorClear)->RangeMultiplier(2)->Range(1, 256)->Complexity();
//
//void VectorInsert(State& state) {
//
//    auto N = state.range(0);
//    std::vector<Small> test {1};
//    Small a{'c'};
//    for (auto _ : state)
//    {
//        for (int i = 0; i < N; ++i)
//        {
//            test.insert(0, a.data[0]);
//        }
//    }
//
//    state.SetComplexityN(N);
//}
//
//BENCHMARK(VectorInsert)->RangeMultiplier(2)->Range(1, 256)->Complexity();
