#include "Small.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash

void LesserThan(State& state) {

    Small a {};
    Small b {};
    for (auto _ : state)
    {
        a<b;
    }
}

BENCHMARK(LesserThan)->Range(1,1);

void Equal(State& state) {

    Small a {};
    Small b {};
    for (auto _ : state)
    {
        a=b;
    }
}

BENCHMARK(Equal)->Range(1,1);

void Hash(State& state) {

    Small a {};
    std::hash<Small> hash;
    for (auto _ : state)
    {
        hash(a);
    }
}

BENCHMARK(Hash)->Range(1,1);