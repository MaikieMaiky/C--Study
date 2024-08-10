#include <cstdlib>
#include <iostream>
#define PRINT(x) std::cout << x << std::endl
#define WAIT system("pause")

#define DUBUG 1
#define RELEASE 0

// 通过宏判断来实现项目开发中的调试需求 或者是发布需求 亦或者是不同平台,功能的实现
#if 1
    #if DUBUG == 1
        #define LOG(x) std::cout << x << std::endl
    #elif RELEASE == 1
        #define LOG(x)
    #endif
#endif


// -E -o macro.i macro.cpp 可以查看预处理后的文件
int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    PRINT(5);
    PRINT("Hello");
    PRINT(5.5);
    LOG("Hello World");
    WAIT;
}
