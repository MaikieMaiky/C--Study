#ifndef __DEQUE_H__
#define __DEQUE_H__

#include <cstddef>
#include <iostream>
#include <vector>

#define DEBUG

/* 使用模板自定义类型 编写属于自己的双向队列 */
/* 在本文件中 将使用链表作为队列的底层 */
/**
 * 实现功能:
 * 1. 入队队首
 * 2. 入队队尾
 * 3. 出队队首
 * 4. 出队队尾
 * 5. 获取队首元素
 * 6. 获取队尾元素
 * 7. 获取队列长度
 * 8. 判断队列是否为空
 * 9. 转换并返回Vector便于打印 
 *
 */

// 链表节点 ListNode
// 由于是双向队列 所以需要有一个指向前一个节点的指针 双向链表节点
template <typename Ty>
struct ListNode
{
    Ty val;
    ListNode *next; // 指向下一个节点
    ListNode *prev; // 指向前一个节点
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};


template <typename Ty>
class Deque
{
private:
    ListNode<Ty> *front;    // 队首
    ListNode<Ty> *rear;     // 队尾
    size_t size;        // 队列长度
public:
    /* 构造函数 -- Constructor */
    Deque() : front(nullptr), rear(nullptr), size(0) 
    {
#ifdef DEBUG
        std::cout << "Deque created!" << std::endl;
#endif
    }

    /* 析构函数 -- Deconstructor */
    ~Deque();

    /* 入队队首 -- push front */
    void push_front(Ty val);

    /* 入队队尾 -- push back */
    void push_back(Ty val);

    /* 出队队首 -- pop front */
    void pop_front();

    /* 出队队尾 -- pop back */
    void pop_back();

    /* 获取队首 -- peek first */
    Ty peek_front() const;

    /* 获取队尾 -- peek back */
    Ty peek_back() const;

    /* 获取队列长度 -- get size */
    size_t get_size() const { return size; }

    /* 判断队列是否为空 -- is empty */
    bool is_empty() const { return size == 0; }

    /* 转换并返回Vector便于打印 -- to vector */
    std::vector<Ty> to_vector() const;
};

template <typename Ty>
/**
 * @brief Destroy the Deque< Ty>:: Deque object
 * 
 */
Deque<Ty>::~Deque()
{
    // 依次释放队列里每一个节点 直到队列为空
    while (front != nullptr)
    {
        ListNode<Ty> *temp = front;
        front = front->next;
        delete temp;
    }
#ifdef DEBUG
    std::cout << "Deque destroyed!" << std::endl;
#endif
}

template <typename Ty>
/**
 * @brief 入队队首
 * 
 * @param val 
 */
void Deque<Ty>::push_front(Ty val)
{
    try 
    {
        // 创建新节点
        ListNode<Ty> *newNode = new ListNode<Ty>(val);
        // 如果队列为空
        if (size == 0)
        {
            front = rear = newNode;
        }
        else
        {
            // 将新节点插入到队首
            front->prev = newNode;
            newNode->next = front;
            front = newNode;
        }
        size++;
    }
    catch (std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }
}

template <typename Ty>
/**
 * @brief 入队队尾
 * 
 * @param val 
 */
void Deque<Ty>::push_back(Ty val)
{
    try
    {
        // 创建新节点
        ListNode<Ty> *newNode = new ListNode<Ty>(val);
        // 如果队列为空
        if (size == 0)
        {
            front = rear = newNode;
        }
        else
        {
            // 将新节点插入到队尾
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        size++;
    }
    catch (std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }
}

template <typename Ty>
/**
 * @brief 出队队首
 * 
 */
void Deque<Ty>::pop_front()
{
    if (size == 0)
    {
        std::cerr << "The queue is empty!" << std::endl;
        return;
    }
    // 保存队首节点
    ListNode<Ty> *temp = front;
    // 如果队列只有一个节点
    if (size == 1)
    {
        front = rear = nullptr;
    }
    else
    {
        // 修改队首指针
        front = front->next;
        front->prev = nullptr;
    }
    // 释放节点
    delete temp;
    size--;
}

template <typename Ty>
/**
 * @brief 出队队尾
 * 
 */
void Deque<Ty>::pop_back()
{
    if (size == 0)
    {
        std::cerr << "The queue is empty!" << std::endl;
        return;
    }
    // 保存队尾节点
    ListNode<Ty> *temp = rear;
    // 如果队列只有一个节点
    if (size == 1)
    {
        front = rear = nullptr;
    }
    else
    {
        // 修改队尾指针
        rear = rear->prev;
        rear->next = nullptr;
    }
    // 释放节点
    delete temp;
    size--;
}

template <typename Ty>
/**
 * @brief 获取队首
 * 
 * @return Ty 
 */
Ty Deque<Ty>::peek_front() const
{
    if (size == 0)
    {
        std::cerr << "The queue is empty!" << std::endl;
        throw std::runtime_error("The queue is empty!");
    }
    return front->val;
}


template <typename Ty>
/**
 * @brief 获取队尾
 * 
 * @return Ty 
 */
Ty Deque<Ty>::peek_back() const
{
    if (size == 0)
    {
        std::cerr << "The queue is empty!" << std::endl;
        throw std::runtime_error("The queue is empty!");
    }
    return rear->val;
}

template <typename Ty>
/**
 * @brief 转换并返回Vector便于打印
 * 
 * @return std::vector<Ty> 
 */
std::vector<Ty> Deque<Ty>::to_vector() const
{
    // 创建一个vector
    std::vector<Ty> res(size);
    // from rear to front
    ListNode<Ty> *temp = rear;
    for (size_t i = 0; i < size; i++)
    {
        res[i] = temp->val;
        temp = temp->prev;
    }
    return res;
}

#endif // __DEQUE_H__