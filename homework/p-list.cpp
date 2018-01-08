#include <benchmark/benchmark.h>
#include <queue>
#include <list>
#include <deque>

std::queue<int, std::list<int>> q;

void prepare() {
  for (int i = 0; i < 1 << 20; i ++)
    q.push(1);
}

void test() {
  for (int i = 0; i < 1 << 20; i ++) {
    benchmark::DoNotOptimize(q.front());
    q.pop();
  }
}

int main() {
  prepare();
  test();
}

