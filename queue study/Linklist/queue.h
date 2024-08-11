#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <cstddef>
#include <stdexcept>
#include <vector>

// listnode struct
template <typename T>
struct ListNode
{
    T data;
    ListNode *next;
    ListNode(T x) : data(x), next(nullptr) {}
};


// class Queue based on Linklist
// alert: 队列需要包含的操作有：入队、出队、判空、获取队首元素
template <typename T>
class Queue
{
private:
    ListNode<T>* front; // 队首
    ListNode<T>* rear;  // 队尾
    size_t size;        // 队列大小

public:
    /* 构造函数 -- Constructor */
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    /* 析构函数 -- Destructor */
    ~Queue();

    /* 入队 -- Enqueue */
    void push(T x);

    /* 出队 -- Dequeue */
    void pop();

    /* 判空 -- isEmpty */
    bool isEmpty() const { return size == 0; }

    /* 获取队首元素 -- get the front element */
    T peek() const;

    /* 获取队列大小 -- get the size of the queue */
    size_t getSize() const { return size; }

    /* 返回队列的vector表示 -- return the vector representation of the queue */
    std::vector<T> toVector() const;
};

template <typename T>
/**
 * @brief Destroy the Queue< T>:: Queue object
 * 
 */
Queue<T>::~Queue()
{
    // 释放队列中的所有节点
    while (front != nullptr)
    {
        // 保存当前节点的指针
        ListNode<T>* temp = front;
        // 移动队首指针到下一个节点
        front = front->next;
        // 释放节点
        delete temp;
    }
}

template <typename T>
/**
 * @brief 入队
 * 
 * @param x 
 */
void Queue<T>::push(T x)
{
    // 创建新节点
    ListNode<T>* newNode = new ListNode<T>(x);
    // 特殊情况:如果队列为空
    if (front == nullptr)
    {
        front = rear = newNode;
    }
    else
    {
        // 将新节点插入到队尾
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

template <typename T>
/**
 * @brief 出队
 * 
 */
void Queue<T>::pop()
{
    // 特殊情况:如果队列为空
    if (isEmpty())
    {
        throw std::out_of_range("Queue<>::pop(): empty queue");
    }
    // 保存当前队首
    ListNode<T>* temp = front;
    // 移动队首指针到下一个节点
    front = front->next;
    // 释放节点
    delete temp;
    size--;
    // 特殊情况:如果队列为空
    if (size == 0)
    {
        rear = nullptr;
    }
}

template <typename T>
/**
 * @brief 获取队首元素
 * 
 * @return T 
 */
T Queue<T>::peek() const
{
    // 特殊情况:如果队列为空
    if (empty())
    {
        throw std::out_of_range("Queue<>::peek(): empty queue");
    }
    return front->data;
}
 
template <typename T>
/**
 * @brief 返回队列的vector表示
 * 
 * @return std::vector<T> 
 */
std::vector<T> Queue<T>::toVector() const
{
    // 创建一个vector
    std::vector<T> vec(size);
    // 遍历队列
    ListNode<T>* temp = front;
    for (size_t i = size; i > 0; i--)
    {
        vec[i - 1] = temp->data;
        temp = temp->next;
    }
    return vec;
}


#endif