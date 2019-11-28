#include "Medium.h"
#include "BenchIncludes.h"
#include <map>

static void MediumMapAt(State& state)
{
    auto N = state.range(0);
    std::map <Medium, Medium> m{};
    Medium a[N];
    Medium b[N];
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
BENCHMARK(MediumMapAt)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


static void MediumMapOperator(State& state)
{
    auto N = state.range(0);
    std::map <Medium, Medium> m{};
    Medium a[N];
    Medium b[N];
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
BENCHMARK(MediumMapOperator)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumMapEmpty(State& state)
{
    auto N = state.range(0);
    std::map <Medium, Medium> m{};
    Medium a[N];
    Medium b[N];
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
BENCHMARK(MediumMapEmpty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumMapSize(State& state)
{
    auto N = state.range(0);
    std::map <Medium, Medium> m;
    Medium a[N];
    Medium b[N];
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
BENCHMARK(MediumMapSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumMapMaxsize(State& state)
{
    auto N = state.range(0);
    std::map <Medium, Medium> m;
    Medium a[N];
    Medium b[N];
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
BENCHMARK(MediumMapMaxsize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumMapClear(State& state)
{
    auto N = state.range(0);
    std::map <Medium, Medium> m;
    Medium a[N];
    Medium b[N];

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
BENCHMARK(MediumMapClear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumMapInsert(State& state)
{
    auto N = state.range(0);
    std::map <Medium, Medium> m;
    Medium a{};
    Medium b{};
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
BENCHMARK(MediumMapInsert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumMapErase(State& state)
{
    auto N = state.range(0);
    std::map <Medium, Medium> m;
    Medium a{};
    Medium b{};
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
BENCHMARK(MediumMapErase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumMapSwap(State& state)
{
    auto N = state.range(0);
    std::map <Medium, Medium> m;
    std::map <Medium, Medium> m2;
    Medium a[N];
    Medium b[N];
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
BENCHMARK(MediumMapSwap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumMapCount(State& state)
{
    auto N = state.range(0);
    std::map <Medium, Medium> m{};
    Medium a[N];
    Medium b[N];
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
BENCHMARK(MediumMapCount)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumMapFind(State& state)
{
    auto N = state.range(0);
    std::map <Medium, Medium> m{};
    Medium a[N];
    Medium b[N];
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
BENCHMARK(MediumMapFind)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumMapEqualrange(State& state)
{
    auto N = state.range(0);
    std::map <Medium, Medium> m{};
    Medium a[N];
    Medium b[N];
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
BENCHMARK(MediumMapEqualrange)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumMapLowerbound(State& state)
{
    auto N = state.range(0);
    std::map <Medium, Medium> m{};
    Medium a[N];
    Medium b[N];
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
BENCHMARK(MediumMapLowerbound)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void MediumMapUpperbound(State& state)
{
    auto N = state.range(0);
    std::map <Medium, Medium> m{};
    Medium a[N];
    Medium b[N];
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
BENCHMARK(MediumMapUpperbound)->RangeMultiplier(2)->Range(1, 1024)->Complexity();