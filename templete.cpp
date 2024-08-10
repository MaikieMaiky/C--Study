#include <array>
#include <cstdlib>
#include <iostream>

// templete practice 
// 1.Print
template<typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

template<typename T, int N>
class Array
{
    using ValueType = T;

private:
    ValueType m_data[N];
public:
    Array() = default;
};

int main()
{
    Print(5);
    Print("Hello");
    Print<float>(5.5);
    system("pause");
    
}