#include <functional>
#include <iostream>
#include <queue>
#include <vector>

// 尝试堆 -- 优先队列的标准库使用
/**
 * std::priority_queue<T, Container, Compare>
 * 常用操作 
 * 1. push() 入堆
 * 2. top() 获取堆顶元素
 * 3. pop() 堆顶元素出栈
 * 4. size() 获取堆大小
 * 5. empty() 判断堆是否为空
 * 6. swap() 交换两个堆
 */

// 确定堆的类型
// 大顶堆 std::less<int>    用来比较两个元素的大小 前一个值小于后一个值则返回true
// 小顶堆 std::greater<int> 用来比较两个元素的大小 前一个值大于后一个值则返回true


int main()
{
    // 默认是大顶堆 初始化大顶堆
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
    // 初始化小顶堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    /* 元素入堆 */
    maxHeap.push(1);
    maxHeap.push(5);
    maxHeap.push(3);
    maxHeap.push(4);
    maxHeap.push(2);

    /* 获取堆顶元素 */
    std::cout << "maxHeap top: " << maxHeap.top() << std::endl; // 5

    /* 堆顶元素出栈 */
    // 出堆元素会形成一个从大到小的堆
    maxHeap.pop(); // 5
    maxHeap.pop(); // 4
    maxHeap.pop(); // 3
    maxHeap.pop(); // 2
    maxHeap.pop(); // 1

    /* 获取堆大小 */
    std::cout << "maxHeap size: " << maxHeap.size() << std::endl; // 0

    /* 判断堆是否为空 */
    std::cout << "maxHeap empty: " << maxHeap.empty() << std::endl; // 1

    /* 输入列表并建堆 */
    std::vector<int> nums = {1, 5, 3, 4, 2};
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap2(nums.begin(), nums.end());
}