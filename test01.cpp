#include <clocale>
#include <locale>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// 函数异化
int Add(int x, int y)
{
    return x + y;
}

int Add(int x, int y, int z)
{
    return x + y + z;
}

double Add(double x, double y)
{
    return x + y;
}

inline int add(int x, int y)
{
    return x + y;
}

inline int maxValue(int x,int y)
{
    return x > y ? x : y;
}

inline double maxValue(double x, double y)
{
    return x > y ? x : y;
}

inline char maxValue(char x, char y)
{
    return x > y ? x : y;
}

inline double CircleArea(double r)
{
    return 3.14159 * r * r;
}

inline double squareArea(double a)
{
    return a * a;
}

inline void printMessage(const string& message, int n = 1)
{
    for (int i = 0; i < n; i++)
    {
        cout << message << endl;
    }
}

inline void Print(const string& str = "Hello World!")
{
    cout << str << endl;
}

/* ---------------------------------------------------------------------------------- */



// 静态成员函数实战
// 学生成绩管理
/* class Student
{
private:
    string name;
    int score;
    // 学生人数
    static int student_num;
    static double total_score;
    static double average_score;
public:
    Student(const string& name, int score);
    static void show();
};

Student::Student(const string& name, int score)
{
    this->name = name;
    this->score = score;
    student_num++;
    total_score += score;
    average_score = total_score / student_num;
}

void Student::show()
{
    cout << "学生人数：" << student_num << endl;
    cout << "总分：" << total_score << endl;
    cout << "平均分：" << average_score << endl;
} */


/* 静态成员函数初始化 */
/* int Student::student_num = 0;
double Student::total_score = 0;
double Student::average_score = 0; */

/* ---------------------------------------------- */

// 友元练习
// 1. 友元函数
// 个人信息: 姓名年龄 \ 身高体重
class Person_Info1
{
private:
    string name;
    int age;
public:
    Person_Info1(const string& name, int age) : name(name), age(age) {};
    void changeName(const string& name)
    {
        this->name = name;
    }
    friend void show(const Person_Info1& p);
};

class Person_Info2
{
private:
    double height;
    double weight;
public:
    Person_Info2(double height, double weight) : height(height), weight(weight) {};
    friend void show(const Person_Info2& p);
};


void show(const Person_Info1& p)
{
    cout << "姓名：" << p.name << endl;
    cout << "年龄：" << p.age << endl;
}

// 标注语:函数重载的意义之一
void show(const Person_Info2& p)
{
    cout << "身高：" << p.height << endl;
    cout << "体重：" << p.weight << endl;
}

/* --------------------------------------------- */

class MyClassA;

class MyClassB {
public:
    void showValue(const MyClassA& obj);
};

class MyClassA {
private:
    int value;
public:
    MyClassA(int v) : value(v) {}
    // 声明MyClassB的成员函数为友元
    friend void MyClassB::showValue(const MyClassA& obj);
};

// MyClassB的成员函数定义
void MyClassB::showValue(const MyClassA& obj) {
    std::cout << obj.value << std::endl;
}


class Myclass
{
private:
    const int x;
    int y;
public:
    Myclass(int x, int y) : x(x), y(y) {}
    void show() const
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
};

//商品信息：每个CartItem对象需要存储商品的名称（字符串）、单价（浮点数）和数量（整数）。
class CartItem
{
private:
    string name;
    float price;
    int quantity;

public:
    //构造函数：类应提供一个构造函数，允许在创建对象时初始化商品名称、单价和数量。
    CartItem(const string& name, float price, int quantity) : name(name), price(price), quantity(quantity) {}
    //总价计算：类需要提供一个成员函数totalPrice()，计算并返回该商品项的总价（单价 * 数量）
    float totalPrice() const
    {
        return price * quantity;
    }
    //显示信息：类需要提供一个成员函数display()，打印商品项的详细信息，包括名称、单价、数量和总价
    void display() const
    {
        cout << "name:" << name << endl;
        cout << "price: " << price << endl;
        cout << "quantity: " << quantity << endl;
        cout << "totalPrice: " << totalPrice() << endl;
    }
    // 修改数量：类需要提供一个成员函数updateQuantity(int newQuantity)，允许修改商品的数量，并确保新的数量不小于0。如果尝试设置一个负数，数量应保持不变，并打印错误信息。
    void updateQuantity(int newQuantity)
    {
        // 判断是否错误
        if (newQuantity < 0)
        {
            cout << "Error: newQuantity < 0" << endl;
        }
        else
        {
            quantity = newQuantity;
        }
    }
};

int main()
{
    CartItem item("apple", 3.5, 5);
    item.display();
    item.updateQuantity(2);
    item.display();
}


