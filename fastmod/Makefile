CXX = clang++
CXXFLAGS = -O2 -std=c++14 -pthread -Wall -Werror -pedantic -fno-omit-frame-pointer

all: fm1 fm2 fm3 fm4

fm1: fm1.cpp
	$(CXX) $(CXXFLAGS) fm1.cpp -o fm1 -lbenchmark

fm2: fm2.cpp
	$(CXX) $(CXXFLAGS) fm2.cpp -o fm2 -lbenchmark

fm3: fm3.cpp
	$(CXX) $(CXXFLAGS) fm3.cpp -o fm3 -lbenchmark

fm4: fm4.cpp
	$(CXX) $(CXXFLAGS) fm4.cpp -o fm4 -lbenchmark

clean:
	rm -rf fm1 fm2 fm3 fm4 perf.data perf.data.old