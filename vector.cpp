#include <iostream>
#include <ostream>
#include <string>
#include <vector>

// STLvector类的学习

struct Stu
{
    int age;
    std::string name;

    Stu(int age, std::string name) : age(age), name(name) {}

    Stu(const Stu &stu) : age(stu.age), name(stu.name)
    {
        std::cout << "Copy" << std::endl;
    }

    ~Stu()
    {
        std::cout << "Delete" << std::endl;
    }
};

// Stu << 打印 运算符重载
std::ostream &operator<<(std::ostream &os, const Stu &stu)
{
    os << "age: " << stu.age << " name: " << stu.name;
    return os;
}

int main()
{
    std::vector<Stu> v;
    v.reserve(3);
    v.emplace_back(18, "Zhang San");
    v.emplace_back(19, "Li Si");
    v.emplace_back(20, "Wang Wu");
    std::vector<Stu>::iterator it = v.begin();
    for (Stu &val : v)
    {
        std::cout << val << std::endl;
    }
}