#include <benchmark/benchmark.h>
#include <queue>
#include <list>
#include <deque>

std::queue<int> q;

void prepare() {
  for (int i = 0; i < 1024; i ++)
    q.push(1);
}

void test() {
  for (int i = 0; i < 1024; i ++) {
    benchmark::DoNotOptimize(q.front());
    q.pop();
  }
}

int main() {
  prepare();
  test();
}

