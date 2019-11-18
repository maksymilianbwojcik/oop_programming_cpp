#include "Medium.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash
void LesserThanMedium(State& state) {

    auto N = state.range(0);
    Medium a {};
    Medium b {};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            a<b;
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(LesserThanMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void EqualMedium(State& state) {

    auto N = state.range(0);
    Medium a {};
    Medium b {};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            a=b;
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(EqualMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void HashMedium(State& state) {

    auto N = state.range(0);
    Medium a {};
    std::hash<Medium> hash;
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            hash(a);
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(HashMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();