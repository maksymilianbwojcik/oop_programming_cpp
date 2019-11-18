#include "BenchIncludes.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <Small.h>

void Vector(State& state) {

    auto N = state.range(0);
    Small a {};
    for (auto _ : state)
    {
        for (int i = 0; i < N; ++i)
        {
            std::vector<Small>;
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(Vector)->RangeMultiplier(2)->Range(1, 256)->Complexity();