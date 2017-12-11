#include <benchmark/benchmark.h>
#include <set>
#include <cstdlib>

std::set<int> ConstructRandomSet(int n) {
    std::set<int> ret;
    for (int i = 0; i < n; i++) {
        ret.insert(rand());
    }
    return ret;
}

static void BM_SetInsert(benchmark::State& state) {
  srand(time(NULL));
  std::set<int> data;
  for (auto _ : state) {
    state.PauseTiming();
    data = ConstructRandomSet(state.range(0));
    state.ResumeTiming();
    for (int j = 0; j < state.range(1); ++j)
      data.insert(rand());
  }
}


BENCHMARK(BM_SetInsert)
    ->Args({1<<10, 128})
    ->Args({2<<10, 128})
    ->Args({4<<10, 128})
    ->Args({8<<10, 128})
    ->Args({1<<10, 512})
    ->Args({2<<10, 512})
    ->Args({4<<10, 512})
    ->Args({8<<10, 512});



// BENCHMARK(BM_SetInsert)->Ranges({{1<<10, 8<<10}, {128, 512}});
/*
static void CustomArguments(benchmark::internal::Benchmark *b) {
    for (int i = 0; i <= 12; i += 4) {
        for (int j = 32; j <= 1024 * 1024; j *= 16) {
            b->Args({i, j});
        }
    }
}
*/
//BENCHMARK(BM_SetInsert)->Apply(CustomArguments);

BENCHMARK_MAIN();