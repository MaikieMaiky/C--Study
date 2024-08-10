#include <iostream>
#include <type_traits>

int main() 
{
    auto add = [](int a, int b) { return a + b; };

    // lambda表达式的类型是一个匿名类型,具体类型是由编译器生成的
    std::cout << "Type of add: " << typeid(decltype(add)).name() << std::endl;

    return 0;
}
