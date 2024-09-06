# 编译选项
CXX = g++
CXXFLAGS = -Wall

.PHONY: clean all run

all: permutations_i permutations_ii subset_sum_i subset_sum_ii n_queens

%: %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
	./$@


# 使用@符号来避免命令的显示
clean:
	@del /Q *.exe