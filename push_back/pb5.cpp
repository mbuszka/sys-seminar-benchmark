#include <benchmark/benchmark.h>
#include <vector>

static void BM_create(benchmark::State &state) {
    for (auto _ : state) {
        std::vector<int> v;
        benchmark::DoNotOptimize(v);
        // forces v to be stored in either memory or register
        // forces compiler to flush pending writes to memory
        // forces compiler to reload values from memory
    }
}

BENCHMARK(BM_create);

static void BM_reserve(benchmark::State &state) {
    for (auto _ : state) {
        std::vector<int> v;
        v.reserve(1);
        benchmark::DoNotOptimize(v);
    }
}

BENCHMARK(BM_reserve);

static void BM_pb(benchmark::State &state) {
    for (auto _ : state) {
        std::vector<int> v;
        v.reserve(1);
        benchmark::DoNotOptimize(v);
        v.push_back(42);
        benchmark::ClobberMemory();
        // forces compiler to flush pending writes to memory
    }
}

BENCHMARK(BM_pb);

BENCHMARK_MAIN();