#include "my_heap.h"
#include <iostream>

// 测试自己的大顶堆

int main()
{
    MyHeap maxheap;
    maxheap.push(3);
    maxheap.push(2);
    maxheap.push(5);
    maxheap.push(1);
    maxheap.push(7);

    // 获取栈顶元素
    std::cout << maxheap.peek() << std::endl;

    // 出栈
    maxheap.pop();
    // 获取栈顶元素
    std::cout << maxheap.peek() << std::endl;

    // 出栈
    maxheap.pop();
    // 获取栈顶元素
    std::cout << maxheap.peek() << std::endl;

    // 出栈
    maxheap.pop();
    // 获取栈顶元素
    std::cout << maxheap.peek() << std::endl;

    // 出栈
    maxheap.pop();
    // 获取栈顶元素
    std::cout << maxheap.peek() << std::endl;
}