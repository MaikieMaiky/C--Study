#include <iostream>
#include "stack.h"

int main()
{
    try 
    {
    myStack<int> stack;

    // Test isEmpty method
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl; // Should output Yes

    // Test push method
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Test top method
    std::cout << "Top element: " << stack.top() << std::endl; // Should output 30

    // Test size method
    std::cout << "Stack size: " << stack.size() << std::endl; // Should output 3

    // Test pop method
    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl; // Should output 20

    // Test toVector method
    std::vector<int> vec = stack.toVector();
    std::cout << "Stack converted to vector: ";
    for (auto val : vec) 
    {
        std::cout << val << " ";
    }
    std::cout << std::endl; // Should output 10 20

    // Test isEmpty method again
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl; // Should output No

    // Test destructor by going out of scope
    } 
    catch (const std::exception& e) 
    {
    std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}