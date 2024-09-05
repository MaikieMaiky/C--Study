# 本makefile旨在学习makefile的使用 有充分的注释

# 编译选项
CXX = g++
CXXFLAGS = -Wall

target = hello world
source = main.cpp func.cpp
object = main.o func.o


# 使用.PHONY声明clean是一个伪目标,不会因为文件名clean而生成文件
.PHONY: clean all run

# 编译命令
# 伪目标 make默认执行第一个编译命令,all会执行所有编译命令
all: $(target)
	@echo "all done"

# 将main.o和func.o链接成可执行文件hello
# $@ 表示目标 也就是***: 的***
$(target): $(object)
	$(CXX)	$(CXXFLAGS) -o $@ $^

# 编译main.cpp
# -c 表示把main.cpp编译成main.o
# $< 表示第一个依赖文件 是***: 右边第一个参数
%.o: %.cpp
	$(CXX)	$(CXXFLAGS) -c $< -o $@



# 伪目标，表示clean是一个虚拟的目标，不会生成任何文件
clean: 
	del /Q *.o *.exe 

run: 
	hello
	world

# 其他命令
# -f 可以在makefile文件名不是makefile的情况下使用 来指定makefile文件名
# -n 表示只打印命令，不执行命令
