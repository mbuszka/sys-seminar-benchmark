// sudo cpupower frequency-set --governor performance
// sudo cpupower frequency-set --governor powersave

#include <benchmark/benchmark.h>
#include <algorithm>
#include <vector>
#include <unistd.h>
#include <ctime>

static void BM_StringCreation(benchmark::State& state) {    
    for (auto _ : state)
        std::string empty_string;
}

BENCHMARK(BM_StringCreation);

static void BM_StringCopy(benchmark::State& state) {
    std::string x = "hello";
    for (auto _ : state) {
        usleep(time(NULL) % 5);
        std::string copy(x);
    }
}

//BENCHMARK(BM_StringCopy);


BENCHMARK(BM_StringCopy)->Repetitions(3)->ComputeStatistics("my_max", [](const std::vector<double> &v) -> double {
    return *(std::max_element(std::begin(v), std::end(v)));
});


BENCHMARK_MAIN();