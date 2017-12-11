#include <benchmark/benchmark.h>
#include <string>
#include <vector>

static void BM_MultiThread(benchmark::State& state) {
    static std::vector<int> v;
    if (state.thread_index == 0) {
        v = std::vector<int>(1024 * state.threads, 42);
        // init
    }

    for (auto _ : state) {
        int sum = 0;
        for (int i = 1024 * state.thread_index; i < 1024 * (state.thread_index + 1); i++) {
            sum += v[i];
        }
        
        benchmark::DoNotOptimize(sum);
    }

    if (state.thread_index == 0) {
        // clean
    }
}

/*
BENCHMARK(BM_MultiThread)->Threads(10);;
*/

BENCHMARK(BM_MultiThread)->ThreadRange(1, 64);

BENCHMARK_MAIN();