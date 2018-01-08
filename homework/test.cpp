#include <benchmark/benchmark.h>
#include <deque>
#include <queue>
#include <list>

static void BM_create_deque(benchmark::State &state) {
    for (auto _ : state) {
        std::queue<int> q;
        benchmark::DoNotOptimize(q);
    }
}

static void BM_create_list(benchmark::State &state) {
    for (auto _ : state) {
        std::queue<int, std::list<int>> q;
        benchmark::DoNotOptimize(q);
    }
}

BENCHMARK(BM_create_deque);
BENCHMARK(BM_create_list);

static void BM_push_list(benchmark::State &state) {
  for (auto _ : state) {
    std::queue<int, std::list<int>> q;
    for (int i = 0; i < state.range(0); i ++) {
      q.push(1);
    }
    benchmark::ClobberMemory();
  }
}

static void BM_push_deque(benchmark::State &state) {
  for (auto _ : state) {
    std::queue<int, std::deque<int>> q;
    for (int i = 0; i < state.range(0); i ++) {
      q.push(1);
    }
    benchmark::ClobberMemory();
  }
}

BENCHMARK(BM_push_list)->Range(1, 8<<9);
BENCHMARK(BM_push_deque)->Range(1, 8<<9);

static void BM_pop_list(benchmark::State &state) {
  for (auto _ : state) {
    // state.PauseTiming();
    std::queue<int, std::list<int>> q;
    for (int i = 0; i < state.range(0); i ++) {
      q.push(1);
    }
    benchmark::ClobberMemory();
    // state.ResumeTiming();
    for (int i = 0; i < state.range(0); i ++) {
      int a = q.front();
      benchmark::DoNotOptimize(a);
      q.pop();
    }
  }
}

static void BM_pop_deque(benchmark::State &state) {
  for (auto _ : state) {
    // state.PauseTiming();
    std::queue<int, std::deque<int>> q;
    for (int i = 0; i < state.range(0); i ++) {
      q.push(1);
    }
    benchmark::ClobberMemory();
    // state.ResumeTiming();
    for (int i = 0; i < state.range(0); i ++) {
      int a = q.front();
      benchmark::DoNotOptimize(a);
      q.pop();
    }
  }
}

BENCHMARK(BM_pop_list)->Range(1, 8<<9);
BENCHMARK(BM_pop_deque)->Range(1, 8<<9);


// static void BM_reserve(benchmark::State &state) {
//     for (auto _ : state) {
//         std::vector<int> v;
//         v.reserve(1);
//         benchmark::DoNotOptimize(v);
//     }
// }
// 
// BENCHMARK(BM_reserve);
// 
// static void BM_pb(benchmark::State &state) {
//     for (auto _ : state) {
//         std::vector<int> v;
//         v.reserve(1);
//         benchmark::DoNotOptimize(v);
//         v.push_back(42);
//         benchmark::ClobberMemory();
//         // forces compiler to flush pending writes to memory
//     }
// }

// BENCHMARK(BM_pb);

BENCHMARK_MAIN();
