#include "Small.h"
#include "BenchIncludes.h"
#include <map>

static void SmallMapAt(State& state)
{
    auto N = state.range(0);
    std::map <Small, Small> m{};
    Small a[N];
    Small b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        m.at(a[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(SmallMapAt)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


static void SmallMapOperator(State& state)
{
    auto N = state.range(0);
    std::map <Small, Small> m{};
    Small a[N];
    Small b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        m[a[0]];
    }
    state.SetComplexityN(N);
}
BENCHMARK(SmallMapOperator)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void SmallMapEmpty(State& state)
{
    auto N = state.range(0);
    std::map <Small, Small> m{};
    Small a[N];
    Small b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        m.empty();
    }
    state.SetComplexityN(N);
}
BENCHMARK(SmallMapEmpty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void SmallMapSize(State& state)
{
    auto N = state.range(0);
    std::map <Small, Small> m;
    Small a[N];
    Small b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        m.size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(SmallMapSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void SmallMapMaxsize(State& state)
{
    auto N = state.range(0);
    std::map <Small, Small> m;
    Small a[N];
    Small b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        m.max_size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(SmallMapMaxsize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void SmallMapClear(State& state)
{
    auto N = state.range(0);
    std::map <Small, Small> m;
    Small a[N];
    Small b[N];

    for(auto _: state)
    {
        state.PauseTiming();
        for(int i=0; i<N; i++)
        {
            a[i].data[0] = rand();
            b[i].data[0] = rand();
            m.insert({a[i],b[i]});
        }
        state.ResumeTiming();

        m.clear();
    }
    state.SetComplexityN(N);
}
BENCHMARK(SmallMapClear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void SmallMapInsert(State& state)
{
    auto N = state.range(0);
    std::map <Small, Small> m;
    Small a{};
    Small b{};
    a.data[0] = rand();
    b.data[0] = rand();

    for(auto _: state)
    {
        m.insert({a,b});

        state.PauseTiming();
        m.erase(a);
        state.ResumeTiming();

    }
    state.SetComplexityN(N);
}
BENCHMARK(SmallMapInsert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void SmallMapErase(State& state)
{
    auto N = state.range(0);
    std::map <Small, Small> m;
    Small a{};
    Small b{};
    a.data[0] = rand();
    b.data[0] = rand();

    for(auto _: state)
    {
        state.PauseTiming();
        m.insert({a,b});
        state.ResumeTiming();

        m.erase(a);
    }
    state.SetComplexityN(N);
}
BENCHMARK(SmallMapErase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void SmallMapSwap(State& state)
{
    auto N = state.range(0);
    std::map <Small, Small> m;
    std::map <Small, Small> m2;
    Small a[N];
    Small b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
        m2.insert({b[i], a[i]});
    }

    for(auto _: state)
    {
        m.swap(m2);
    }
    state.SetComplexityN(N);
}
BENCHMARK(SmallMapSwap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void SmallMapCount(State& state)
{
    auto N = state.range(0);
    std::map <Small, Small> m{};
    Small a[N];
    Small b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        m.count(a[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(SmallMapCount)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void SmallMapFind(State& state)
{
    auto N = state.range(0);
    std::map <Small, Small> m{};
    Small a[N];
    Small b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        m.find(a[rand()%N]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(SmallMapFind)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void SmallMapEqualrange(State& state)
{
    auto N = state.range(0);
    std::map <Small, Small> m{};
    Small a[N];
    Small b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        m.equal_range(b[rand()%N]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(SmallMapEqualrange)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void SmallMapLowerbound(State& state)
{
    auto N = state.range(0);
    std::map <Small, Small> m{};
    Small a[N];
    Small b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        m.lower_bound(a[rand()%N]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(SmallMapLowerbound)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void SmallMapUpperbound(State& state)
{
    auto N = state.range(0);
    std::map <Small, Small> m{};
    Small a[N];
    Small b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        m.upper_bound(a[rand()%N]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(SmallMapUpperbound)->RangeMultiplier(2)->Range(1, 1024)->Complexity();