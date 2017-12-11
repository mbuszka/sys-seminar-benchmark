CXX = clang++
CXXFLAGS = -std=c++11 -pthread -Wall -Wextra -pedantic

all: intro1 intro2 intro3 intro4 intro5 intro6

intro1: intro1.cpp
	$(CXX) $(CXXFLAGS) intro1.cpp -o intro1 -lbenchmark

intro2: intro2.cpp
	$(CXX) $(CXXFLAGS) intro2.cpp -o intro2 -lbenchmark

intro3: intro3.cpp
	$(CXX) $(CXXFLAGS) intro3.cpp -o intro3 -lbenchmark

intro4: intro4.cpp
	$(CXX) $(CXXFLAGS) intro4.cpp -o intro4 -lbenchmark

intro5: intro5.cpp
	$(CXX) $(CXXFLAGS) intro5.cpp -o intro5 -lbenchmark

intro6: intro6.cpp
	$(CXX) $(CXXFLAGS) intro6.cpp -o intro6 -lbenchmark

clean:
	rm -rf intro1 intro2 intro3 intro4 intro5 intro6