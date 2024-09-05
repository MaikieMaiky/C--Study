# 编译选项
CXX = g++
CXXFLAGS = -Wall

.PHONY: clean all run

all: permutations_i permutations_ii subset_sum_i_naive

permutations_i: permutations_i.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
	./$@

permutations_ii: permutations_ii.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
	./$@

subset_sum_i_naive: subset_sum_i_naive.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
	./$@

# 使用@符号来避免命令的显示
clean:
	@del /Q *.exe