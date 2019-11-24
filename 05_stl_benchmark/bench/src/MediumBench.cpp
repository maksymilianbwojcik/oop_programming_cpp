#include "Medium.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash

void LesserThanMedium(State& state) {

    Medium a {};
    Medium b {};
    for (auto _ : state)
    {
        a<b;
    }
}

BENCHMARK(LesserThanMedium)->Range(1,1);

void EqualMedium(State& state) {

    Medium a {};
    Medium b {};
    for (auto _ : state)
    {
        a=b;
    }
}

BENCHMARK(EqualMedium)->Range(1,1);

void HashMedium(State& state) {

    Medium a {};
    std::hash<Medium> hash;
    for (auto _ : state)
    {
        hash(a);
    }
}

BENCHMARK(HashMedium)->Range(1,1);