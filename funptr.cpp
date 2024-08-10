#include <iostream>


void HelloWorld()
{
    std::cout << "Hello World" << std::endl;
}

// 从未想过的方式
typedef void (*HelloWorldFunction)();
using HelloWorldFunction = void (*)();

int main()
{
    void (*pFunction)() = HelloWorld;
    // another good way to use auto keyword
    auto pFunction1 = HelloWorld;
    // an unblievable way to use typedef (function pointer)
    HelloWorldFunction pFunction2 = HelloWorld;
    pFunction();
    pFunction1();
    pFunction2();
}