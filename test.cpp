#include <array>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <tuple>
using namespace std;

#define PI 3.1415

/* 1. C++ 基本语法
变量和数据类型
输入输出（cin 和 cout）
条件语句和循环 */



/* int main() 
{
    MyClass obj;
    // obj.privateVar = 10;  // 错误：private 成员不能在类外部访问
    // obj.privateMethod();  // 错误：private 成员不能在类外部访问

    obj.setPrivateVar(10);  // 通过公共方法访问 private 成员
    std::cout << "PrivateVar: " << obj.getPrivateVar() << std::endl;
    // 计算Myclass对象的大小
    std::cout << "Size of MyClass: " << sizeof(MyClass) << std::endl;
    return 0;
}
 */

// 字符串链表
/* class Node
{
public:
    string data;
    Node *next;
    Node(string data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        this->head = NULL;
    }
    // 添加节点
    void addNode(string data)
    {
        Node *newNode = new Node(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else
        {
            Node *temp = this->head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    // 打印链表
    void display()
    {
        Node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
        cout << endl;
    }
    // 删除节点
    void deleteNode(string data)
    {
        Node *temp = this->head;
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                if (prev == NULL)
                {
                    this->head = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Node not found" << endl;
    }
};


// 菜单
// 1.添加节点 --> 输入字符串
// 2.打印链表
// 0.退出
// 打印菜单
void menu()
{
    cout << "1.Add Node" << endl;
    cout << "2.Print List" << endl;
    cout << "3.Delete Node" << endl;
    cout << "0.Exit" << endl;
}


int main()
{
    int choice;
    LinkedList linkedList;
    do 
    {
        menu();
        cin >> choice;
        switch (choice) 
        {
            case 1:
            {
                string data;
                cout << "please enter a string" << endl;
                cin >> data;
                linkedList.addNode(data);
                break;
            }
            case 2:
            {
                linkedList.display();
                break;
            }
            case 3:
            {
                string data;
                cout << "please enter a string" << endl;
                cin >> data;
                linkedList.deleteNode(data);
                break;
            }
            case 0:
            {
                cout << "Exit" << endl;
                break;
            }
            default:
            {
                cout << "invalid input" << endl;
                break;
            }
        }
    } while (choice != 0);
    return 0;
}
 */


// 模板练习 不同游戏角色
// 返回最大值 请不要进行代码补全
template <typename T>

T Max(T a, T b)
{
    return a > b ? a : b;
}

template <typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 模板类 
template <typename T>
class MyContainer
{
public:
    T data;
    MyContainer(T d) : data(d) {}
    void display()
    {
        cout << "Data: " << this->data << endl;
    }
};
        
// 模板类数组
template <typename T, int SIZE>
class FixedArray
{
public:
    T arr[SIZE];

    void Set(int index, T value)
    {
        if (index >= 0 && index < SIZE)
        {
            arr[index] = value;
        }
        else
        {
            cout << "Index out of range" << endl;
        }
    }

    T Get(int index)
    {
        if (index >= 0 && index < SIZE)
        {
            return arr[index];
        }
        return T();
    }
    
    int Size()
    {
        return SIZE;
    }
};

// 模板异化
template <int SIZE>
class FixedArray<bool, SIZE>
{
public:
    bool arr[SIZE];
    void Set(int index, bool value)
    {
        if (index >= 0 && index < SIZE)
        {
            arr[index] = value;
        }
        else
        {
            cout << "Index out of range" << endl;
        }
    }
    bool Get(int index)
    {
        if (index >= 0 && index < SIZE)
        {
            return arr[index];
        }
        return true;
    }
    int Size()
    {
        return SIZE;
    }
};

// 模板异化
template <int SIZE>
class FixedArray<int, SIZE>
{
public:
    int arr[SIZE];
    void Set(int index, int value)
    {
        if (index >= 0 && index < SIZE)
        {
            arr[index] = value;
        }
        else
        {
            cout << "Index out of range" << endl;
        }
    }
    int Get(int index)
    {
        if (index >= 0 && index < SIZE)
        {
            return arr[index];
        }
        return 1;
    }
    int Size()
    {
        return SIZE;
    }
};

// 斐波那契数列 模板元编程练习
template <int N>
struct Fibonacci
{
    enum {value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value};
};

// 模板异化 递归终止条件
template <>
struct Fibonacci<0>
{
    enum {value = 0};
};

template <>
struct Fibonacci<1>
{
    enum {value = 1};
};


// 类里面的static成员变量
class Entity
{
public:
    static int x;
    static int y;

    static void Print()
    {
        cout << x << ", " << y << endl;
    }
};



int Entity::x = 0;
int Entity::y = 0;


inline void Print(const string& str)
{
    cout << str << endl;
}

class Player
{
private:
    string name;
    int hp;
    int xp;
    // 等级
    int level;
public:

    explicit Player(const string& name) : name(name), hp(100), xp(0), level(1) {}

    // 打印个人信息 
    friend ostream& operator<<(ostream& os, const Player& player);

    ~Player() {cout << name << " is destroyed" << endl;}
};

ostream& operator<<(ostream& os, const Player& player)
{
    os << "Name: " << player.name << endl;
    os << "HP: " << player.hp << endl;
    os << "XP: " << player.xp << endl;
    os << "Level: " << player.level << endl;
    return os;
}

string GiveName(const string& name)
{
    string newName = "Mr." + name;
    return newName;
}


int main()
{
    Player player1("Shibo");
    cout << player1 << endl;
    //Entity e1;
    //e1.x = 2;
    //e1.y = 3;
    //e1.Print();
    //Entity::Print();

}

