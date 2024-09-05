# 编译选项
CXX = g++
CXXFLAGS = -Wall

.PHONY: clean all run

all: permutations_i permutations_ii

permutations_i: permutations_i.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
	./$@

permutations_ii: permutations_ii.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
	./$@

clean:
	rm -f permutations_i permutations_ii