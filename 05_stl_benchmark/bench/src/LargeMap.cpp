#include "Large.h"
#include "BenchIncludes.h"
#include <map>

static void LargeMapAt(State& state)
{
    auto N = state.range(0);
    std::map <Large, Large> m{};
    Large a[N];
    Large b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        DoNotOptimize(m.at(a[0]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeMapAt)->RangeMultiplier(2)->Range(1, 8)->Complexity();


static void LargeMapOperator(State& state)
{
    auto N = state.range(0);
    std::map <Large, Large> m{};
    Large a[N];
    Large b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        DoNotOptimize(m[a[0]]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeMapOperator)->RangeMultiplier(2)->Range(1, 8)->Complexity();

static void LargeMapEmpty(State& state)
{
    auto N = state.range(0);
    std::map <Large, Large> m{};
    Large a[N];
    Large b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        DoNotOptimize(m.empty());
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeMapEmpty)->RangeMultiplier(2)->Range(1, 8)->Complexity();

static void LargeMapSize(State& state)
{
    auto N = state.range(0);
    std::map <Large, Large> m;
    Large a[N];
    Large b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        DoNotOptimize(m.size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeMapSize)->RangeMultiplier(2)->Range(1, 8)->Complexity();

static void LargeMapMaxsize(State& state)
{
    auto N = state.range(0);
    std::map <Large, Large> m;
    Large a[N];
    Large b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        DoNotOptimize(m.max_size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeMapMaxsize)->RangeMultiplier(2)->Range(1, 8)->Complexity();

static void LargeMapClear(State& state)
{
    auto N = state.range(0);
    std::map <Large, Large> m;
    Large a[N];
    Large b[N];

    for(auto _: state)
    {
        for(int i=0; i<N; i++)
        {
            a[i].data[0] = rand();
            b[i].data[0] = rand();
            m.insert({a[i],b[i]});
        }

        DoNotOptimize(m);
        m.clear();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeMapClear)->RangeMultiplier(2)->Range(1, 8)->Complexity();

static void LargeMapInsert(State& state)
{
    auto N = state.range(0);
    std::map <Large, Large> m;
    Large a{};
    Large b{};
    a.data[0] = rand();
    b.data[0] = rand();

    for(auto _: state)
    {
        DoNotOptimize(m);
        m.insert({a,b});
        ClobberMemory();

        m.erase(a);

    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeMapInsert)->RangeMultiplier(2)->Range(1, 8)->Complexity();

static void LargeMapErase(State& state)
{
    auto N = state.range(0);
    std::map <Large, Large> m;
    Large a{};
    Large b{};
    a.data[0] = rand();
    b.data[0] = rand();

    for(auto _: state)
    {
        m.insert({a,b});

        DoNotOptimize(m);
        m.erase(a);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeMapErase)->RangeMultiplier(2)->Range(1, 8)->Complexity();

static void LargeMapSwap(State& state)
{
    auto N = state.range(0);
    std::map <Large, Large> m;
    std::map <Large, Large> m2;
    Large a[N];
    Large b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
        m2.insert({b[i], a[i]});
    }

    for(auto _: state)
    {
        DoNotOptimize(m);
        m.swap(m2);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeMapSwap)->RangeMultiplier(2)->Range(1, 8)->Complexity();

static void LargeMapCount(State& state)
{
    auto N = state.range(0);
    std::map <Large, Large> m{};
    Large a[N];
    Large b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        DoNotOptimize(m.count(a[0]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeMapCount)->RangeMultiplier(2)->Range(1, 8)->Complexity();

static void LargeMapFind(State& state)
{
    auto N = state.range(0);
    std::map <Large, Large> m{};
    Large a[N];
    Large b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        DoNotOptimize(m.find(a[rand()%N]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeMapFind)->RangeMultiplier(2)->Range(1, 8)->Complexity();

static void LargeMapEqualrange(State& state)
{
    auto N = state.range(0);
    std::map <Large, Large> m{};
    Large a[N];
    Large b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        DoNotOptimize(m.equal_range(b[rand()%N]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeMapEqualrange)->RangeMultiplier(2)->Range(1, 8)->Complexity();

static void LargeMapLowerbound(State& state)
{
    auto N = state.range(0);
    std::map <Large, Large> m{};
    Large a[N];
    Large b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        DoNotOptimize(m.lower_bound(a[rand()%N]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeMapLowerbound)->RangeMultiplier(2)->Range(1, 8)->Complexity();

static void LargeMapUpperbound(State& state)
{
    auto N = state.range(0);
    std::map <Large, Large> m{};
    Large a[N];
    Large b[N];
    for(int i=0; i<N; i++)
    {
        a[i].data[0] = rand();
        b[i].data[0] = rand();
        m.insert({a[i],b[i]});
    }

    for(auto _: state)
    {
        DoNotOptimize(m.upper_bound(a[rand()%N]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(LargeMapUpperbound)->RangeMultiplier(2)->Range(1, 8)->Complexity();