#ifndef __STACK_H__
#define __STACK_H__

#include <cstddef>
#include <vector>
#include <stdexcept>

// listNode Structure template declaration
template <typename T>
struct listNode
{
    using DATA_TYPE = T;
    
    DATA_TYPE data;
    listNode* next;
    listNode(DATA_TYPE x) : data(x), next(nullptr) {}
};


// stack class declaration
template <typename T>
class myStack
{
    using DATA_TYPE = T;

private:
    listNode<DATA_TYPE>* stktop;   // 将链表的头结点作为栈顶 -- use the head node of the linked list as the top of the stack
    size_t stksize;         // 栈的大小 -- the size of the stack
public:
    /* 构造函数 -- constructor */
    myStack() : stktop(nullptr), stksize(0) {}

    /* 析构函数 -- destructor */
    ~myStack();

    /* 入栈 -- push */
    void push(DATA_TYPE x);

    /* 出栈 -- pop */
    void pop();

    /* 获取栈顶元素 -- get the top element */
    DATA_TYPE top();

    /* 获取栈的大小 -- get the size of the stack */
    size_t size() const { return stksize; }

    /* 判断栈是否为空 -- judge whether the stack is empty */
    bool isEmpty() const { return stksize == 0; }

    /* 将栈转换为vector -- convert the stack to a vector */
    std::vector<DATA_TYPE> toVector() const;
};


template <typename T>
/**
 * @brief Destroy the my Stack<T>::my Stack object
 * 
 */
myStack<T>::~myStack()
{
    // 依次释放栈中的元素
    while (stktop != nullptr)
    {
        listNode<T>* temp = stktop;
        stktop = stktop->next;
        delete temp;
    }
}

template <typename T>
/**
 * @brief 入栈
 * 
 * @param x 
 */
void myStack<T>::push(T x)
{
    // 申请新节点
    listNode<T>* newNode = new listNode<T>(x);
    // 新节点指向栈顶
    newNode->next = stktop;
    // 切换栈顶为新节点
    stktop = newNode;
    // 栈大小加1
    stksize++;
}

template <typename T>
/**
 * @brief 出栈
 * 
 */
void myStack<T>::pop()
{
    // 如果栈为空,则直接返回
    if (isEmpty())
    {
        return;
    }
    // 保存栈顶元素
    listNode<T>* temp = stktop;
    // 栈顶指向下一个元素
    stktop = stktop->next;
    // 释放栈顶元素
    delete temp;
    // 栈大小减1
    stksize--;
}

template <typename T>
/**
 * @brief 获取栈顶元素
 * 
 * @return T 
 */
T myStack<T>::top()
{
    // 如果栈为空,则抛出异常
    if (isEmpty())
    {
        throw std::out_of_range("stack is empty");
    }
    return stktop->data;
}

template <typename T>
/**
 * @brief 将栈转换为vector
 * 
 * @return std::vector<T> 
 */
std::vector<T> myStack<T>::toVector() const
{
    listNode<T>* temp = stktop;
    std::vector<T> vec(stksize);
    // 从栈底到栈顶依次复制元素
    for (size_t i = stksize; i > 0; i--)
    {
        vec[i - 1] = temp->data;
        temp = temp->next;
    }
    return vec;
}



#endif // __STACK_H__