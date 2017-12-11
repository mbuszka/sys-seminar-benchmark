#include <benchmark/benchmark.h>
#include <vector>

static void escape(void *p) {
    asm volatile("" : : "g"(p) : "memory");
}

static void clobber() {
    asm volatile("" : : : "memory");
}

static void BM_create(benchmark::State &state) {
    for (auto _ : state) {
        std::vector<int> v;
        escape(&v); // v będzie w pamięci!
    }
}

BENCHMARK(BM_create);

static void BM_reserve(benchmark::State &state) {
    for (auto _ : state) {
        std::vector<int> v;
        v.reserve(1);
        escape(v.data());
    }
}

BENCHMARK(BM_reserve);

static void BM_pb(benchmark::State &state) {
    for (auto _ : state) {
        std::vector<int> v;
        v.reserve(1);
        escape(v.data());
        v.push_back(42);
        clobber();
    }
}

BENCHMARK(BM_pb);

BENCHMARK_MAIN();