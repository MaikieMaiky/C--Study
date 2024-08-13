#ifndef __DEQUE_H__
#define __DEQUE_H__

#include <cstddef>
#include <iostream>
#include <vector>

// 基于环形数组(vector 不使用扩容)实现的双向队列 -- Deque based on circular array (vector without expansion)
// 读取数据 -- peek


#define DEBUG

template <typename Ty>
/**
 * @brief 双向队列类 -- Deque class
 * 
 * @warning 需要注意的是 这里并不直接在Deque里面存储rear指针
 * 是因为在使用环形数组的时候 rear = (front + size - 1) % capacity
 */
class Deque
{
private:
    std::vector<Ty> nums;   // 存放双向队列元素的数组 -- Array to store elements of deque
    size_t front;           // 队首指针 -- Front pointer
    size_t size;            // 队列长度 -- Length of deque
public:
    /* 构造函数 -- Constructor */
    Deque(size_t capacity = 10) : nums(capacity), front(0), size(0) 
    {
#ifdef DEBUG
        std::cout << "Deque created!" << std::endl;
#endif
    }
    
    /* 析构函数 -- Deconstructor */
    ~Deque() 
    {
#ifdef DEBUG
        std::cout << "Deque destroyed!" << std::endl;
#endif
    }

    /* 计算偏移之后索引 -- offset index */
    size_t index(int i) const { return (front + nums.size() + i) % nums.size(); }

    /* 计算队尾索引 -- rear index calculate */
    size_t rear_index() const { return index(size); }

    /* 入队队首 -- push front */
    void push_front(Ty val);

    /* 入队队尾 -- push back */
    void push_back(Ty val);
    
    /* 出队队首 -- pop front */
    void pop_front();

    /* 出队队尾 -- pop back */
    void pop_back();

    /* 获取队首元素 -- get front */
    Ty peek_front() const;

    /* 获取队尾元素 -- get back */
    Ty peek_back() const;

    /* 获取队列长度 -- get size */
    size_t get_size() const { return size; }

    /* 获取队列容量 -- get capacity */
    size_t get_capacity() const { return nums.size(); }

    /* 判断队列是否为空 -- is empty */
    bool is_empty() const { return size == 0; }

    /* 转换并返回Vector便于打印 -- to vector */
    std::vector<Ty> to_vector() const;
};

template <typename Ty>
/**
 * @brief 入队队首
 * 
 * @param val 入队元素
 */
void Deque<Ty>::push_front(Ty val)
{
    // 判断队列是否已满
    if (size == nums.size())
    {
        std::cerr << "Deque is full!" << std::endl;
        return;
    }

    // 队首指针后移
    front = index(-1);

    // 入队
    nums[front] = val;
    size++;
}

template <typename Ty>
/**
 * @brief 入队队尾
 * 
 * @param val 入队元素
 */
void Deque<Ty>::push_back(Ty val)
{
    // 判断队列是否已满
    if (size == nums.size())
    {
        std::cerr << "Deque is full!" << std::endl;
        return;
    }

    // 入队
    nums[rear_index()] = val;
    size++;
}

template <typename Ty>
/**
 * @brief 出队队首
 * 
 */
void Deque<Ty>::pop_front()
{
    // 判断队列是否为空
    if (is_empty())
    {
        std::cerr << "Deque is empty!" << std::endl;
        return;
    }

    // 队首指针前移
    front = index(1);
    size--;
}

template <typename Ty>
/**
 * @brief 出队队尾
 * 
 */
void Deque<Ty>::pop_back()
{
    // 判断队列是否为空
    if (is_empty())
    {
        std::cerr << "Deque is empty!" << std::endl;
        return;
    }

    // 出队
    size--;
}

template <typename Ty>
/**
 * @brief 获取队首元素
 * 
 * @return Ty 队首元素
 */
Ty Deque<Ty>::peek_front() const
{
    // 判断队列是否为空
    if (is_empty())
    {
        std::cerr << "Deque is empty!" << std::endl;
        return Ty();
    }

    return nums[front];
}

template <typename Ty>
/**
 * @brief 获取队尾元素
 * 
 * @return Ty 队尾元素
 */
Ty Deque<Ty>::peek_back() const
{
    // 判断队列是否为空
    if (is_empty())
    {
        std::cerr << "Deque is empty!" << std::endl;
        return Ty();
    }

    return nums[index(size - 1)];
}

template <typename Ty>
/**
 * @brief 转换并返回Vector便于打印
 * 
 * @return std::vector<Ty> 
 */
std::vector<Ty> Deque<Ty>::to_vector() const
{
    std::vector<Ty> res(size);
    for (size_t i = 0; i < size; i++)
    {
        res[i] = nums[index(i)];
    }
    return res;
}


#endif // __DEQUE_H__