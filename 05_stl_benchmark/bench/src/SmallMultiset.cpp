#include "Small.h"
#include "BenchIncludes.h"
#include <unordered_set>

static void UnorderedMultisetEmpty(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Small> test;
    Small a[N];
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
BENCHMARK(UnorderedMultisetEmpty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void UnorderedMultisetSize(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Small> test;
    Small a[N];
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
BENCHMARK(UnorderedMultisetSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void UnorderedMultisetMaxsize(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Small> test;
    Small a[N];
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
BENCHMARK(UnorderedMultisetMaxsize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void UnorderedMultisetClear(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Small> test;
    Small a[N];

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
BENCHMARK(UnorderedMultisetClear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void UnorderedMultisetInsert(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Small> test;
    Small a{};
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
BENCHMARK(UnorderedMultisetInsert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void UnorderedMultisetErase(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Small> test;
    Small a{};
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
BENCHMARK(UnorderedMultisetErase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void UnorderedMultisetSwap(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Small> test;
    std::unordered_multiset<Small> w;
    Small a[N];
    Small b[N];
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
BENCHMARK(UnorderedMultisetSwap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void UnorderedMultisetCount(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Small> test;
    Small a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        test.count(a[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMultisetCount)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void UnorderedMultisetFind(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Small> test;
    Small a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        test.find(a[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMultisetFind)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void UnorderedMultisetEqualrange(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Small> test;
    Small a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        test.equal_range(a[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMultisetEqualrange)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void UnorderedMultisetRehash(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Small> test;
    Small a[N];
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
BENCHMARK(UnorderedMultisetRehash)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void UnorderedMultisetReserve(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Small> test;
    Small a[N];
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
BENCHMARK(UnorderedMultisetReserve)->RangeMultiplier(2)->Range(1, 1024)->Complexity();