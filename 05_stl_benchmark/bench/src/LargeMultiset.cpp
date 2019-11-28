#include "Large.h"
#include "BenchIncludes.h"
#include <unordered_set>

static void LargeUnorderedMultisetEmpty(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Large> test;
    Large a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        DoNotOptimize(test);
        test.empty();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeUnorderedMultisetEmpty)->RangeMultiplier(2)->Range(1, 32)->Complexity();

static void LargeUnorderedMultisetSize(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Large> test;
    Large a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        DoNotOptimize(test.size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeUnorderedMultisetSize)->RangeMultiplier(2)->Range(1, 32)->Complexity();

static void LargeUnorderedMultisetMaxsize(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Large> test;
    Large a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        DoNotOptimize(test.max_size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeUnorderedMultisetMaxsize)->RangeMultiplier(2)->Range(1, 32)->Complexity();

static void LargeUnorderedMultisetClear(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Large> test;
    Large a[N];

    for(auto _: state)
    {

        for(int i=0; i<N; i++)
        {
            a[i].data[0] = rand();
            test.insert(a[i]);
        }


        DoNotOptimize(test);

        test.clear();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeUnorderedMultisetClear)->RangeMultiplier(2)->Range(1, 32)->Complexity();

static void LargeUnorderedMultisetInsert(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Large> test;
    Large a{};
    a.data[0] = rand();

    for(auto _: state)
    {
        DoNotOptimize(test);
        test.insert(a);
        ClobberMemory();

        test.erase(a);

    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeUnorderedMultisetInsert)->RangeMultiplier(2)->Range(1, 32)->Complexity();

static void LargeUnorderedMultisetErase(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Large> test;
    Large a{};
    a.data[0] = rand();

    for(auto _: state)
    {

        test.insert(a);

        DoNotOptimize(test);

        test.erase(a);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeUnorderedMultisetErase)->RangeMultiplier(2)->Range(1, 32)->Complexity();

static void LargeUnorderedMultisetSwap(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Large> test;
    std::unordered_multiset<Large> w;
    Large a[N];
    Large b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        test.insert(a[i]);
        w.insert(b[i]);
    }
    for(auto _: state)
    {
        DoNotOptimize(test);
        test.swap(w);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeUnorderedMultisetSwap)->RangeMultiplier(2)->Range(1, 32)->Complexity();

static void LargeUnorderedMultisetCount(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Large> test;
    Large a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        DoNotOptimize(test.count(a[rand()%N]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeUnorderedMultisetCount)->RangeMultiplier(2)->Range(1, 32)->Complexity();

static void LargeUnorderedMultisetFind(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Large> test;
    Large a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        DoNotOptimize(test.find(a[rand()%N]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeUnorderedMultisetFind)->RangeMultiplier(2)->Range(1, 32)->Complexity();

static void LargeUnorderedMultisetEqualrange(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Large> test;
    Large a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {
        DoNotOptimize(test.equal_range(a[rand()%N]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeUnorderedMultisetEqualrange)->RangeMultiplier(2)->Range(1, 32)->Complexity();

static void LargeUnorderedMultisetRehash(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Large> test;
    Large a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {

        int num = rand()%10;

        DoNotOptimize(test);
        test.rehash(num);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeUnorderedMultisetRehash)->RangeMultiplier(2)->Range(1, 32)->Complexity();

static void LargeUnorderedMultisetReserve(State& state)
{
    auto N = state.range(0);
    std::unordered_multiset<Large> test;
    Large a[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        test.insert(a[i]);
    }
    for(auto _: state)
    {

        int num = rand()%10;

        DoNotOptimize(test);
        test.reserve(num);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeUnorderedMultisetReserve)->RangeMultiplier(2)->Range(1, 32)->Complexity();