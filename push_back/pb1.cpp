#include <benchmark/benchmark.h>
#include <vector>

static void BM(benchmark::State &state) {
    for (auto _ : state) {
        std::vector<int> v;
        v.push_back(42);
    }
}

BENCHMARK(BM);

BENCHMARK_MAIN();

// sudo perf record --call-graph=dwarf ./pb1
// sudo perf report -G
// h key
// to get asm view of function press a
// in asm view: s, k (compile with -g)