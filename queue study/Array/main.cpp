#include <iostream>
#include "queue.h"

int main() 
{
    // 创建一个队列 test Constructor method
    Queue<int> q(10);

    // test empty method
    std::cout << "Queue is empty: " << std::boolalpha << q.isEmpty() << std::endl;

    // test enqueue method (push)
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << "Queue after pushing 1, 2, 3: ";

    // test toVector method
    std::vector<int> vec = q.toVector();
    // Print
    for (int val : vec) 
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // test peek method
    std::cout << "Front element: " << q.peek() << std::endl;

    // test pop method
    q.pop();
    std::cout << "Queue after popping one element: ";
    vec = q.toVector();
    for (int val : vec) 
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // test getSize method
    std::cout << "Queue size: " << q.getSize() << std::endl;

    // 异常处理
    try 
    {
        while (!q.isEmpty()) 
        {
            q.pop();
        }
        q.pop(); // 这里应该抛出异常
    } 
    catch (const std::underflow_error& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}