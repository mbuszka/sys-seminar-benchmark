#include <benchmark/benchmark.h>
#include <string>
#include <vector>

static void BM_UserCounter(benchmark::State& state) {
    uint64_t my_cnt1 = 0, my_cnt2 = 0;
    
    for (auto _ : state) {
        if (rand() % 0x42 == 0) {
            my_cnt1++;
            my_cnt2 += my_cnt1;
        
            state.SkipWithError("ERROR!111!");
            break;
        }
    }

    state.counters["my_cnt1"] = my_cnt1;
    state.counters["my_cnt2"] = my_cnt2;
}

BENCHMARK(BM_UserCounter);

BENCHMARK_MAIN();