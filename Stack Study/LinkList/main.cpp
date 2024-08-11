#include <iostream>
#include "stack.h"

int main()
{
    try 
    {
        myStack<int> stack;

        // Test basic stack operations
        stack.push(10);
        stack.push(20);
        stack.push(30);

        std::cout << "Top element: " << stack.top() << std::endl; // Should output 30

        stack.pop();
        std::cout << "Top element: " << stack.top() << std::endl; // Should output 20

        // Test toVector method
        std::vector<int> vec = stack.toVector();
        std::cout << "Stack converted to vector: ";
        for (auto val : vec) 
        {
            std::cout << val << " ";
        }
        std::cout << std::endl; // Should output 10 20

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}