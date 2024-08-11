#ifndef __STACK_H__
#define __STACK_H__

#include <vector>
#include <stdexcept>

// 使用vector实现栈 -- implement the stack using vector
// vector是一个动态数组,可以自动扩容,所以我们可以直接使用vector来实现栈 而不需要自己实现动态数组

template <typename T>
class myStack
{
    using Data_Type = T;

private:
    std::vector<Data_Type> stk; // 使用vector来实现栈 -- implement the stack using vector

public:
    /* 构造函数 -- constructor */
    myStack() = default;

    /* 析构函数 -- destructor */
    ~myStack() = default;

    /* 入栈 -- push */
    void push(Data_Type x);

    /* 出栈 -- pop */
    void pop();

    /* 获取栈顶元素 -- get the top element */
    Data_Type top();
    
    /* 获取栈的大小 -- get the size of the stack */
    size_t size() const { return stk.size(); }

    /* 判断栈是否为空 -- judge whether the stack is empty */
    bool isEmpty() const { return stk.empty(); }

    /* 返回栈的vector表示 -- return the vector representation of the stack */
    std::vector<Data_Type> toVector() const { return stk; }
};

template <typename Data_Type>
/**
 * @brief 入栈
 * 
 * @param x 
 */
void myStack<Data_Type>::push(Data_Type x)
{
    try
    {
        stk.push_back(x);
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error("Stack<>::push(): failed to push element");
    }
}



template <typename Data_Type>
/**
 * @brief 出栈
 * 
 */
void myStack<Data_Type>::pop()
{
    if (isEmpty())
    {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    stk.pop_back();
}

template <typename Data_Type>
/**
 * @brief 获取栈顶元素
 * 
 * @return Data_Type 
 */
Data_Type myStack<Data_Type>::top()
{
    if (isEmpty())
    {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return stk.back();
}


#endif