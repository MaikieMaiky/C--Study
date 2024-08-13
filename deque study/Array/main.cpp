#include "deque.h"

// 本文件用于测试自己编写的双向队列 -- This file is used to test the deque written by myself
// 方法测试 -- Method test

int main()
{
    // 创建一个双向队列 -- Create a deque
    Deque<int> dq(10);

    std::cout << "Is deque empty? " << (dq.is_empty() ? "Yes" : "No") << std::endl;

    // 测试入队队首 -- Test push front
    dq.push_front(10);
    dq.push_front(20);
    dq.push_front(30);

    // 测试入队队尾 -- Test push back
    dq.push_back(40);
    dq.push_back(50);
    dq.push_back(60);

    // 打印队列内容 -- Print deque content
    std::vector<int> vec = dq.to_vector();
    std::cout << "Deque content: ";
    for (int val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 测试获取队首元素 -- Test peek front
    std::cout << "Front element: " << dq.peek_front() << std::endl;

    // 测试获取队尾元素 -- Test peek back
    std::cout << "Rear element: " << dq.peek_back() << std::endl;

    // 测试出队队首 -- Test pop front
    dq.pop_front();
    std::cout << "After pop front, deque content: ";
    vec = dq.to_vector();
    for (int val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 测试出队队尾 -- Test pop back
    dq.pop_back();
    std::cout << "After pop back, deque content: ";
    vec = dq.to_vector();
    for (int val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 测试获取队列长度 -- Test get size
    std::cout << "Deque size: " << dq.get_size() << std::endl;

    // 测试判断队列是否为空 -- Test is empty
    std::cout << "Is deque empty? " << (dq.is_empty() ? "Yes" : "No") << std::endl;

    return 0;
}