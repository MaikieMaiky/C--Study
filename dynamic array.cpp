#include <cstddef>
#include <cstdlib>
#include <iostream>

// 动态数组C++ 实现 加模板 
template <typename T>
class SeqList 
{
    using ValueType = T;
public:
    ValueType* arr;
    size_t size;                  // 有效数据个数
    size_t capacity;              // 容量

    /* 构造函数 */
    SeqList(size_t capacity = 10) : arr(new ValueType[capacity]), size(0), capacity(capacity) { std::cout << "Dynamic SeqList Constructed Successfully" << std::endl; }

    /* 析构函数 */
    ~SeqList() { delete[] arr; std::cout << "Dynamic SeqList Destructed Successfully" << std::endl; }

    /* 检查容量 */
    void CheckCapacity();
    
    /* 头插 */
    void Pushfront(ValueType x);

    /* 尾插 */
    void Pushback(ValueType x);

    /* 插入 */
    void Insert(size_t p, ValueType x);

    /* 头删 */  
    void Popfront();

    /* 尾删 */
    void Popback();

    /* 删除 */
    void Erase(size_t p);

    /* 打印 */
    void Print() const;

    /* 额外练习 运算符重载[] */
    ValueType& operator[](size_t p) { return arr[p]; }
};

template <typename T>
/**
 * @brief 检查动态数组容量,如果满了则扩容
 * 
 */
void SeqList<T>::CheckCapacity()
{
    // 如果数据量已满,则扩容
    if (size == capacity)
    {
        try
        {
            // 申请新的空间
            ValueType* temp = new ValueType[capacity * 2];

            // 拷贝数据
            for (size_t i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }

            // 释放原空间
            delete[] arr;

            // 指向新空间 容量翻倍
            arr = temp;
            capacity *= 2;
        }
        catch (std::bad_alloc& e)
        {
            std::cerr << e.what() << std::endl;
            exit(1);
        }
    }
}

template <typename T>
/**
 * @brief 头插
 * 
 * @param x 
 */
void SeqList<T>::Pushfront(ValueType x)
{
    CheckCapacity();
    for (size_t i = size; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
    size++;
}

template <typename T>
/**
 * @brief 尾插
 * 
 * @param x 
 */
void SeqList<T>::Pushback(ValueType x)
{
    CheckCapacity();
    arr[size] = x;
    size++;
}

template <typename T>
/**
 * @brief 插入
 * 
 * @param p 
 * @param x 
 */
void SeqList<T>::Insert(size_t p, ValueType x)
{
    // 检查输入位置是否合法
    if (p < 0 || p > size)
    {
        std::cerr << "Invalid position" << std::endl;
        return;
    }

    CheckCapacity();

    // 将指定位置后的数据后移
    for (size_t i = size; i > p; i--)
    {
        arr[i] = arr[i - 1];
    }

    // 插入数据
    arr[p] = x;
    size++;
}

template <typename T>
/**
 * @brief 头删
 * 
 */
void SeqList<T>::Popfront()
{
    // 检查动态数组是否为空
    if (size == 0)
    {
        std::cerr << "Empty SeqList" << std::endl;
        return;
    }

    // 将数据前移
    for (size_t i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

template <typename T>
/**
 * @brief 尾删
 * 
 */
void SeqList<T>::Popback()
{
    // 检查动态数组是否为空
    if (size == 0)
    {
        std::cerr << "Empty SeqList" << std::endl;
        return;
    }
    size--;
}

template <typename T>
/**
 * @brief 删除
 * 
 * @param p 
 */
void SeqList<T>::Erase(size_t p)
{
    // 检查输入是否合法
    if (p < 0 || p > size)
    {
        std::cerr << "Invalid position" << std::endl;
        return;
    }

    // 将输入后面的数据前移
    for (size_t i = p; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

template <typename T>
/**
 * @brief 打印
 * 
 */
void SeqList<T>::Print() const
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // 创建一个容量为5的动态数组
    SeqList<int> list(5);

    // 测试尾插
    list.Pushback(1);
    list.Pushback(2);
    list.Pushback(3);
    list.Pushback(4);
    list.Pushback(5);
    std::cout << "After Pushback: ";
    list.Print(); // 输出: 1 2 3 4 5
    system("pause");

    // 测试头插
    list.Pushfront(0);
    std::cout << "After Pushfront: ";
    list.Print(); // 输出: 0 1 2 3 4 5
    system("pause");

    // 测试插入
    list.Insert(3, 99);
    std::cout << "After Insert at position 3: ";
    list.Print(); // 输出: 0 1 2 99 3 4 5
    system("pause");

    // 测试头删
    list.Popfront();
    std::cout << "After Popfront: ";
    list.Print(); // 输出: 1 2 99 3 4 5
    system("pause");

    // 测试尾删
    list.Popback();
    std::cout << "After Popback: ";
    list.Print(); // 输出: 1 2 99 3 4
    system("pause");

    // 测试删除
    list.Erase(2);
    std::cout << "After Erase at position 2: ";
    list.Print(); // 输出: 1 2 3 4
    system("pause");

    // 测试运算符重载[]
    list[2] = 100;
    std::cout << "After list[2] = 100: ";
    list.Print(); // 输出: 1 2 100 4
    system("pause");
}