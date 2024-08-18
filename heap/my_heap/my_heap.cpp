#include "my_heap.h"

/* 构造函数 */
MyHeap::MyHeap() : heapSize(0) {}

MyHeap::MyHeap(std::vector<int> nums) : heapSize(nums.size())
{
    // 将数组原封不动添加进堆
    maxheap = nums;
    // 从最后一个非叶子节点开始, 从右至左, 从下至上进行堆化
    for (int i = parent(heapSize - 1); i >= 0; i--)
        siftDown(i);
}

/* 析构函数 */
MyHeap::~MyHeap() {}

/* 获取堆的大小 */
int MyHeap::size() const { return heapSize; }

/* 判断堆是否为空 */
bool MyHeap::isEmpty() const { return heapSize == 0; }

/* 访问堆顶元素 */
int MyHeap::peek() const 
{ 
    // 判空
    if (heapSize == 0) 
        throw std::out_of_range("heap is empty");
    return maxheap[0]; 
}

/* 入堆 */
void MyHeap::push(int val)
{
    // 添加节点
    maxheap.push_back(val);
    // 堆大小加一
    heapSize++;
    // 从底到顶堆化
    siftUp(heapSize - 1);
}

/* 出堆 */
void MyHeap::pop()
{
    // 判空
    if (heapSize == 0) 
        throw std::out_of_range("heap is empty");
    // 将根节点和最右叶节点交换(交换首元素和尾元素)
    std::swap(maxheap[0], maxheap[heapSize - 1]);
    // 删除最后一个元素
    maxheap.pop_back();
    // 堆大小减一
    heapSize--;
    // 从顶到底堆化
    siftDown(0);
}

/* 从节点 i 开始, 从底至顶堆化 */
void MyHeap::siftUp(int i)
{
    while (true)
    {
        // 获取父节点
        int parentIndex = parent(i);
        // 当"越过根节点" 或 "节点无需修复" 时停止
        if (i <= 0 || maxheap[parentIndex] >= maxheap[i]) 
            break;
        // 交换节点
        std::swap(maxheap[parentIndex], maxheap[i]);
        // 循环向上堆化
        i = parentIndex;
    }
}

/* 从节点 i 开始, 从顶至底堆化 */
void MyHeap::siftDown(int i)
{
    while (true)
    {
        // 判断该节点和其左右子节点中最大的节点
        int maxIndex = i;
        int leftIndex = left(i);
        int rightIndex = right(i);
        // 判断左子节点
        if (leftIndex < heapSize && maxheap[leftIndex] > maxheap[maxIndex]) 
            maxIndex = leftIndex;
        // 判断右子节点
        if (rightIndex < heapSize && maxheap[rightIndex] > maxheap[maxIndex]) 
            maxIndex = rightIndex;
        // 若当前节点最大 或者索引leftIndex和rightIndex越界时,则停止堆化
        if (maxIndex == i) 
            break;
        // 交换节点
        std::swap(maxheap[i], maxheap[maxIndex]);
        // 循环向下堆化
        i = maxIndex;
    }
}

// 获取左子节点 左子节点 = 2 * 父节点 + 1
int MyHeap::left(int i) const { return 2 * i + 1; }

// 获取右子节点 右子节点 = 2 * 父节点 + 2
int MyHeap::right(int i) const { return 2 * i + 2; }

// 获取父节点 父节点 = (子节点 - 1) / 2
int MyHeap::parent(int i) const { return (i - 1) / 2; }