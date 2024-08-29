
/* 哨兵划分 */
#include <utility>
#include <vector>
int partition(std::vector<int> &nums, int left, int right)
{
    // 以nums[left]为基准元素
    int pivot = nums[left];
    int i = left;
    int j = right;
    // 循环,直到i=j
    while (i < j)
    {
        // 从右向左查找第一个小于基准元素的元素
        while (i < j && nums[j] >= pivot)
            j--;
        // 将小于基准元素的元素放到左边
        nums[i] = nums[j];
        // 从左向右查找第一个大于基准元素的元素
        while (i < j && nums[i] <= pivot)
            i++;
        // 交换这两个元素
        std::swap(nums[i], nums[j]);
    }
    // 将基准元素放到正确的位置
    std::swap(nums[left], nums[i]);
    return i; // 返回基准元素的索引
}

/**
 * @brief 快速排序算法
 * 
 * @param nums 待排序的整数向量
 * @param left 排序范围的左边界
 * @param right 排序范围的右边界
 * 
 * @details
 * 该函数实现了快速排序算法，使用了尾递归优化。
 * 算法步骤如下：
 * 1. 使用while循环代替递归，直到左右边界相遇
 * 2. 使用partition函数进行分区，获取基准元素的位置
 * 3. 比较左右子数组的大小，对较小的子数组进行递归调用
 * 4. 更新边界，继续对较大的子数组进行排序
 */
void QuickSort(std::vector<int> &nums, int left, int right)
{
    // 当左边界小于右边界时继续排序
    while (left < right)
    {
        // 进行分区，获取基准元素的位置
        int pivot = partition(nums, left, right);
        
        // 比较左右子数组的大小，对较小的子数组进行递归调用
        if (pivot - left < right - pivot)
        {
            // 对左子数组进行递归排序
            QuickSort(nums, left, pivot - 1);
            // 更新左边界，继续对右子数组进行排序
            left = pivot + 1;
        }
        else
        {
            // 对右子数组进行递归排序
            QuickSort(nums, pivot + 1, right);
            // 更新右边界，继续对左子数组进行排序
            right = pivot - 1;
        }
    }
}
