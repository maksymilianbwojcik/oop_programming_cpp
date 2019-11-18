#include "Small.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash

void LesserThan(State& state) {

    auto N = state.range(0);
    Small a {};
    Small b {};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            a<b;
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(LesserThan)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void Equal(State& state) {

    auto N = state.range(0);
    Small a {};
    Small b {};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            a=b;
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(Equal)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void Hash(State& state) {

    auto N = state.range(0);
    Small a {};
    std::hash<Small> hash;
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            hash(a);
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(Hash)->RangeMultiplier(2)->Range(1, 1024)->Complexity();