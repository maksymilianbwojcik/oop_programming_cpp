#include "Medium.h"
#include "BenchIncludes.h"
#include <unordered_set>

static void MediumUnorderedMultisetEmpty(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Medium> test;
    Medium a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        test.empty();
    }
    state.SetComplexityN(N);
}
BENCHMARK(MediumUnorderedMultisetEmpty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumUnorderedMultisetSize(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Medium> test;
    Medium a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        test.size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(MediumUnorderedMultisetSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumUnorderedMultisetMaxsize(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Medium> test;
    Medium a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        test.max_size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(MediumUnorderedMultisetMaxsize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumUnorderedMultisetClear(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Medium> test;
    Medium a[N];

    for(auto _: state)
    {
        state.PauseTiming();
        for(int i=0; i<N; i++)
        {
            a[i].data[0] = rand();
            test.insert(a[i]);
        }
        state.ResumeTiming();

        test.clear();
    }
    state.SetComplexityN(N);
}
BENCHMARK(MediumUnorderedMultisetClear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumUnorderedMultisetInsert(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Medium> test;
    Medium a{};
    a.data[0] = rand();

    for(auto _: state)
    {
        test.insert(a);

        state.PauseTiming();
        test.erase(a);
        state.ResumeTiming();
    }
    state.SetComplexityN(N);
}
BENCHMARK(MediumUnorderedMultisetInsert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumUnorderedMultisetErase(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Medium> test;
    Medium a{};
    a.data[0] = rand();

    for(auto _: state)
    {
        state.PauseTiming();
        test.insert(a);
        state.ResumeTiming();

        test.erase(a);
    }
    state.SetComplexityN(N);
}
BENCHMARK(MediumUnorderedMultisetErase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumUnorderedMultisetSwap(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Medium> test;
    std::unordered_multiset<Medium> w;
    Medium a[N];
    Medium b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        test.insert(a[i]);
        w.insert(b[i]);
    }
    for(auto _: state)
    {
        test.swap(w);
    }
    state.SetComplexityN(N);
}
BENCHMARK(MediumUnorderedMultisetSwap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumUnorderedMultisetCount(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Medium> test;
    Medium a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        test.count(a[rand()%N]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(MediumUnorderedMultisetCount)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumUnorderedMultisetFind(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Medium> test;
    Medium a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        test.find(a[rand()%N]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(MediumUnorderedMultisetFind)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumUnorderedMultisetEqualrange(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Medium> test;
    Medium a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        test.equal_range(a[rand()%N]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(MediumUnorderedMultisetEqualrange)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumUnorderedMultisetRehash(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Medium> test;
    Medium a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        state.PauseTiming();
        int num = rand()%10;
        state.ResumeTiming();

        test.rehash(num);
    }
    state.SetComplexityN(N);
}
BENCHMARK(MediumUnorderedMultisetRehash)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumUnorderedMultisetReserve(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Medium> test;
    Medium a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        state.PauseTiming();
        int num = rand()%10;
        state.ResumeTiming();

        test.reserve(num);
    }
    state.SetComplexityN(N);
}
BENCHMARK(MediumUnorderedMultisetReserve)->RangeMultiplier(2)->Range(1, 1024)->Complexity();