# 编译选项
CXX = g++
CXXFLAGS = -Wall

.PHONY: all clean

all: min_path_sum

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
	./$@

clean:
	@del /Q *.exe