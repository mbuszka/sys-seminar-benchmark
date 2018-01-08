CXX = clang++
CXXFLAGS = -O3 -std=c++14 -pthread -Wall -Werror -pedantic -g -fno-omit-frame-pointer

all: test p-test

test: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -o test -lbenchmark

p-test: p-test.cpp
	$(CXX) $(CXXFLAGS) p-test.cpp -o p-test -lbenchmark

clean:
	rm -rf test p-test perf.data perf.data.old
