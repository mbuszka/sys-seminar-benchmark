#include <benchmark/benchmark.h>
#include <string>

static void BM_StringCompare(benchmark::State& state) {
    std::string s1(state.range(0), '-');
    std::string s2(state.range(0), '-');

    for (auto _ : state) {
        benchmark::DoNotOptimize(s1.compare(s2)); // ???
        //s1.compare(s2);
    }

    state.SetComplexityN(state.range(0));
}


BENCHMARK(BM_StringCompare)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);


/*
BENCHMARK(BM_StringCompare)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity();
*/

//BENCHMARK(BM_StringCompare) 
//    ->Unit(benchmark::kMicrosecond)
//    ->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);

BENCHMARK_MAIN();

// --benchmark_filter=BM_StringCompare/1024
// --benchmark_format=console|json|csv
// --benchmark_out=<filename>