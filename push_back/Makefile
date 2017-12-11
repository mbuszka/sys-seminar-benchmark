CXX = clang++
CXXFLAGS = -O3 -std=c++14 -pthread -Wall -Werror -pedantic -g -fno-omit-frame-pointer

all: pb1 pb2 pb3 pb4 pb5

pb1: pb1.cpp
	$(CXX) $(CXXFLAGS) pb1.cpp -o pb1 -lbenchmark

pb2: pb2.cpp
	$(CXX) $(CXXFLAGS) pb2.cpp -o pb2 -lbenchmark

pb3: pb3.cpp
	$(CXX) $(CXXFLAGS) pb3.cpp -o pb3 -lbenchmark

pb4: pb4.cpp
	$(CXX) $(CXXFLAGS) pb4.cpp -o pb4 -lbenchmark

pb5: pb5.cpp
	$(CXX) $(CXXFLAGS) pb5.cpp -o pb5 -lbenchmark

clean:
	rm -rf pb1 pb2 pb3 pb4 pb5 perf.data perf.data.old