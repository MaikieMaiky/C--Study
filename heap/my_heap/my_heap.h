#ifndef _MY_HEAP_H_
#define _MY_HEAP_H_

#include <stdexcept>
#include <vector>

/* 使用完全二叉树来表示堆 */
/* 因为是完全二叉树 所以很适合使用数组来存储堆 */
/* 节点指针使用以下公式进行计算 */

// 以下是一个大顶堆的实现
class MyHeap
{
public:
    /* 构造函数 */
    MyHeap();
    MyHeap(std::vector<int> nums);
    /* 析构函数 */
    ~MyHeap();

    /* 获取堆的大小 */
    int size() const;
    /* 判断堆是否为空 */
    bool isEmpty() const;
    /* 访问堆顶元素 */
    int peek() const;
    /* 入堆 */
    void push(int val);
    /* 出堆 */
    void pop();

private:
    // 获取左子节点 左子节点 = 2 * 父节点 + 1
    int left(int i) const;
    // 获取右子节点 右子节点 = 2 * 父节点 + 2
    int right(int i) const;
    // 获取父节点 父节点 = (子节点 - 1) / 2
    int parent(int i) const;
    /* 从节点 i 开始, 从底至顶堆化 */
    void siftUp(int i);
    /* 从节点 i 开始, 从顶至底堆化 */
    void siftDown(int i);

    std::vector<int> maxheap;
    int heapSize;
};

#endif // MY_HEAP_H