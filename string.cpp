// 字符串示例及讲解
#include <iostream>
#include <string>

using namespace std;
using string = std::string;

class Animal 
{
public:
    std::string name;

    // 构造函数
    Animal(std::string n) : name(n) {}
    // 成员函数
    void eat() {
        std::cout << name << " is eating.\n";
    }
};



int main()
{
    std::string name1 = "Wang";
    std::string name2 = "Yi";
    char name3[] = "Yi";
    std::cout << name1 + name2 << std::endl;
    std::cout << sizeof(name3) << std::endl;
    string name4;
    name4 = cin.get();
    cout << name4 << endl;
}