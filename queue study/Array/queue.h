#ifndef  __QUEUE_H__
#define __QUEUE_H__

#include <cstddef>
#include <stdexcept>
#include <vector>
// use circle array to implement queue

template <typename Ty>
class Queue
{
private:
    Ty* data;
    size_t front;
    size_t size;
    size_t capacity;

public:
    /* 构造函数 -- Constructor */
    Queue(size_t x) : data(new Ty[x]), front(0), size(0), capacity(x) {}

    /* 析构函数 -- Destructor */
    ~Queue() { delete[] data; }

    /* 入队 -- Enqueue */
    void push(Ty x);

    /* 出队 -- Dequeue */
    void pop();

    /* 判断是否为空 -- isEmpty */
    bool isEmpty() const { return size == 0; }

    /* 获取队首元素 -- get the front element */
    Ty peek() const;

    /* 获取队列大小 -- get the size of the queue */
    size_t getSize() const { return size; }

    /* 获取队列容量 -- get the capacity of the queue */
    size_t getCapacity() const { return capacity; }

    /* 返回队列的vector表示 -- return the vector representation of the queue */
    std::vector<Ty> toVector() const;
};

template <typename Ty>
/**
 * @brief 入队
 * 
 * @param x 
 */
void Queue<Ty>::push(Ty x)
{
    // if the queue is full, throw an exception
    if (size == capacity)
    {
        throw std::overflow_error("The queue is full.");
    }
    // 计算队尾位置
    size_t rear = (front + size) % capacity;
    // 将元素放入队尾
    data[rear] = x;
    // 队列大小加一
    size++;
}

template <typename Ty>
/**
 * @brief 出队
 * 
 */
void Queue<Ty>::pop()
{
    // if the queue is empty, throw an exception
    if (size == 0)
    {
        throw std::underflow_error("The queue is empty.");
    }
    // 队首指针后移一位
    front = (front + 1) % capacity;
    // 队列大小减一
    size--;
}

template <typename Ty>
/**
 * @brief 获取队首元素
 * 
 * @return Ty 
 */
Ty Queue<Ty>::peek() const
{
    // if the queue is empty, throw an exception
    if (size == 0)
    {
        throw std::underflow_error("The queue is empty.");
    }
    return data[front];
}

template <typename Ty>
/**
 * @brief 返回队列的vector表示
 * 
 * @return std::vector<Ty> 
 */
std::vector<Ty> Queue<Ty>::toVector() const
{
    std::vector<Ty> vec(size);
    for (size_t i = 0; i < size; i++)
    {
        vec[i] = data[(front + i) % capacity];
    }
    return vec;
}

#endif // __QUEUE_H__