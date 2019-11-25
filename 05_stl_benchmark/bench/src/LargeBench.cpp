#include "Large.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash

void LesserThanLarge(State& state) {

    Large a {};
    Large b {};
    for (auto _ : state)
    {
        a<b;
    }
}

BENCHMARK(LesserThanLarge);

void EqualLarge(State& state) {

    Large a {};
    Large b {};
    for (auto _ : state)
    {
        a=b;
    }
}

BENCHMARK(EqualLarge);

void HashLarge(State& state) {

    Large a {};
    std::hash<Large> hash;
    for (auto _ : state)
    {
        hash(a);
    }
}

BENCHMARK(HashLarge);