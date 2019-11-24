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

BENCHMARK(LesserThanLarge)->Range(1,1);

void EqualLarge(State& state) {

    Large a {};
    Large b {};
    for (auto _ : state)
    {
        a=b;
    }
}

BENCHMARK(EqualLarge)->Range(1,1);

void HashLarge(State& state) {

    Large a {};
    std::hash<Large> hash;
    for (auto _ : state)
    {
        hash(a);
    }
}

BENCHMARK(HashLarge)->Range(1,1);