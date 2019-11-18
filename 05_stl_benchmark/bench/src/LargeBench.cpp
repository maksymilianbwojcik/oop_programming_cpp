#include "Large.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash
void LesserThanLarge(State& state) {

    auto N = state.range(0);
    Large a {};
    Large b {};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            a<b;
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(LesserThanLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void EqualLarge(State& state) {

    auto N = state.range(0);
    Large a {};
    Large b {};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            a=b;
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(EqualLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void HashLarge(State& state) {

    auto N = state.range(0);
    Large a {};
    std::hash<Large> hash;
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            hash(a);
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(HashLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();