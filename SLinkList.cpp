/* 使用C++复刻单向链表 */
#include <cassert>
#include <cstdio>
#include <iostream>
#include <new>

#define DEBUG
#define SLTdatatype int

/**
 * @brief 链表节点结构体
 * 
 * @warning 要使用指针,不能使用引用,因为引用不能使用nullptr
 */
struct SLTNode
{
    SLTdatatype data;
    SLTNode* next;

    /* 构造函数 */
    SLTNode(SLTdatatype x) : data(x), next(nullptr) {}
};

/**
 * @brief 单向链表类
 */
class SLinkList
{
public:
    SLTNode* head; // 头指针

    /* 构造函数 */
    SLinkList() : head(nullptr) { std::cout << "Single Link List Constructed Successfully" << std::endl; }

    /* 析构函数 */
    ~SLinkList();

    /* 头插新节点 */    
    void push_front(SLTdatatype x);

    /* 尾插新节点 */
    void push_back(SLTdatatype x);

    /* 指定元素前插入 */
    void insert_before(SLTdatatype val, SLTdatatype x);

    /* 指定元素后插入 */
    void insert_after(SLTdatatype val, SLTdatatype x);

    /* 头删节点 */
    void pop_front(void);

    /* 尾删节点 */
    void pop_back(void);
    
    /* 打印链表 */
    void print(void) const;
};


/**
 * @brief 单链表析构函数
 * 
 */
SLinkList::~SLinkList()
{
    SLTNode* node = head;
    while (node != nullptr)
    {
        SLTNode* tempNode = node;
        node = node->next;
        delete tempNode;
    }
    #ifdef DEBUG
    std::cout << "Single Link List Destructed Successfully" << std::endl;
    #endif
}


/**
 * @brief 单链表头插节点函数
 * 
 * @param x SLTdatatype 新节点存储的值
 */
void SLinkList::push_front(SLTdatatype x)
{
    // 异常处理
    // 当抛出异常之后 会中断作用域内的剩余代码
    try 
    {
        // 申请节点空间
        SLTNode* node = new SLTNode(x);
        // 将申请的节点的下一个节点改为当前链表的头
        node->next = head;
        // 将链表的头改为新申请的节点
        head = node;
    }
    // 异常处理
    catch (std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        exit(1);
    }
}


/**
 * @brief 单链表尾插节点函数
 * 
 * @param x SLTdatatype 新节点存储的值
 */
void SLinkList::push_back(SLTdatatype x)
{
    // 异常处理
    // 当抛出异常之后 会中断作用域内的剩余代码
    try 
    {
        // 申请节点空间
        SLTNode* node = new SLTNode(x);
        SLTNode* tailnode = head;

        // 如果链表为空 则直接插入
        if (tailnode == nullptr)
        {
            head = node;
        }
        // 如果链表不为空 则寻找尾节点
        else
        {
            while (tailnode->next != nullptr)
            {
                tailnode = tailnode->next;
            }
            // 将尾节点的下一个节点改为新申请的节点
            tailnode->next = node;
        }
    }
    // 异常处理
    catch (std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        exit(1);
    }
}

/**
 * @brief 单链表指定元素前插入
 * 
 * @param val 指定元素的值
 * @param x 新节点存储的值
 */
void SLinkList::insert_before(SLTdatatype val, SLTdatatype x)
{
    // 判断链表是否为空
    if (head == nullptr)
    {
        perror("head is nullptr, can't insert");
        exit(1);
    }

    // 特殊情况：插入到头节点之前
    if (head->data == val)
    {
        try 
        {
            SLTNode* node = new SLTNode(x);
            node->next = head;
            head = node;
        }
        catch (std::bad_alloc &e)
        {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            exit(1);
        }
        return;
    }

    // 找到需要插入的元素的前一个节点
    SLTNode* prevNode = head;
    while (prevNode->next != nullptr && prevNode->next->data != val)
    {
        prevNode = prevNode->next;
    }

    // 如果找到指定节点
    if (prevNode->next != nullptr)
    {
        // 插入新节点
        try 
        {
            SLTNode* node = new SLTNode(x);
            // 新节点指向需要插入的元素
            node->next = prevNode->next;
            // 需要插入的元素的前一个元素指向新节点
            prevNode->next = node;
        }
        // 异常处理
        catch (std::bad_alloc &e)
        {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            exit(1);
        }    
    }
    // 没有找到指定节点
    else
    {
        std::cout << "data not fount, insert failed" << std::endl;
    }
}


/**
 * @brief 单链表指定元素后插入
 * 
 * @param val 指定元素的值
 * @param x 新节点存储的值
 */
void SLinkList::insert_after(SLTdatatype val, SLTdatatype x)
{
    // 判断链表是否为空
    if (head == nullptr)
    {
        perror("head is nullptr, can't insert");
        exit(1);
    }

    // 找到需要插入的元素
    SLTNode* node = head;
    while (node != nullptr && node->data != val)
    {
        node = node->next;
    }

    // 如果找到指定节点
    if (node != nullptr)
    {
        // 插入新节点
        try 
        {
            SLTNode* newNode = new SLTNode(x);
            // 新节点指向需要插入的元素的下一个节点
            newNode->next = node->next;
            // 需要插入的元素指向新节点
            node->next = newNode;
        }
        // 异常处理
        catch (std::bad_alloc &e)
        {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            exit(1);
        }
    }
    // 没有找到指定节点
    else
    {
        std::cout << "data not fount, insert failed" << std::endl;
    }
}


/**
 * @brief 单链表头删函数
 * 
 */
void SLinkList::pop_front(void)
{
    // 判断链表是否为空
    if (head == nullptr)
    {
        perror("head is nullptr, can't pop");
        exit(1);
    }

    /* 删除头节点 */
    // 保存头节点的下一个节点
    SLTNode* tempNode = head->next;
    // 释放头节点
    delete head;
    // 更改链表头节点
    head = tempNode;
}

/**
 * @brief 单链表尾删函数
 * 
 */
void SLinkList::pop_back(void)
{
    // 判断链表是否为空
    if (head == nullptr)
    {
        perror("head is nullptr, can't pop");
        exit(1);
    }

    // 如果只有一个节点 则直接删除
    if (head->next == nullptr)
    {   
        delete head;
        head = nullptr;
    }
    // 如果有多个节点 则找到尾节点的前一个节点 并删除尾节点
    else
    {
        SLTNode* prevTail = head;
        while (prevTail->next->next != nullptr)
        {
            prevTail = prevTail->next;
        }
        delete prevTail->next;
        
        // 尾节点的下一个节点置为nullptr
        prevTail->next = nullptr;
    }
}


/**
 * @brief 打印单链表
 * 
 */
void SLinkList::print(void) const
{
    SLTNode* node = head;
    while (node != nullptr)
    {
        std::cout << node->data << "->";
        node = node->next;
    }
    std::cout << "nullptr" << std::endl;
}


int main()
{
    // 创建链表对象
    SLinkList list;

    // 测试头插
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    std::cout << "After push_front operations: ";
    list.print(); // 30->20->10->nullptr

    // 测试尾插
    list.push_back(40);
    list.push_back(50);
    std::cout << "After push_back operations: ";
    list.print(); // 30->20->10->40->50->nullptr

    // 测试指定元素前插入
    list.insert_before(10, 25);
    std::cout << "After insert_before operation: ";
    list.print(); // 30->20->25->10->40->50->nullptr

    // 测试指定元素后插入
    list.insert_after(10, 35);
    std::cout << "After insert_after operation: ";
    list.print(); // 30->20->25->10->35->40->50->nullptr

    // 测试头删
    list.pop_front();
    std::cout << "After pop_front operation: ";
    list.print(); // 20->25->10->35->40->50->nullptr

    // 测试尾删
    list.pop_back();
    std::cout << "After pop_back operation: ";
    list.print(); // 20->25->10->35->40->nullptr

    return 0;
}