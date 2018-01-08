CXX = clang++
CXXFLAGS = -O3 -std=c++14 -pthread -Wall -Werror -pedantic -g -fno-omit-frame-pointer

all: test p-list p-deque

test: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -o test -lbenchmark

p-list: p-list.cpp
	$(CXX) $(CXXFLAGS) p-list.cpp -o p-list -lbenchmark

p-deque: p-deque.cpp
	$(CXX) $(CXXFLAGS) p-deque.cpp -o p-deque -lbenchmark

clean:
	rm -rf test p-list p-deque list.perf deque.perf
