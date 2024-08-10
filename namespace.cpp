#include <iostream>

// namespace的 apple
namespace apple 
{
    void Print(const char* text)
    {
        std::cout << text << std::endl;
    }
}

// namespace orange
namespace orange
{
    void Print(const char* text)
    {
        std::cout << "hello " << text << std::endl;
    }
}

// namespac嵌套 cherno的使用技巧?可能不适合我
namespace fruit {namespace functions{
    
    void Print(const char* text)
    {
        std::cout << "fruit functions " << text << std::endl;
    }

}}

int main()
{
    using namespace apple;
    using namespace orange;
    Print("Hello World");
    apple::Print("Hello World");
    orange::Print("Hello World");
    fruit::functions::Print("Hello World");
}