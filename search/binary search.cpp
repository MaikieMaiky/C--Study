/* 二分查找 算法实现 */
//值得注意的是，由于 i 和 j 都是 int 类型，因此 i + j 可能会超出 int 类型的取值范围。
// 为了避免大数越界，我们通常采用公式 m=⌊i+(j−i)/2⌋ 来计算中点。
#include <vector>


int binarySearch(std::vector<int> &nums, int target)
{
    // 初始化左右边界
    int i = 0;
    int j = nums.size() - 1;
    // 循环,当搜索区间为空时退出 (i > j)
    while (i <= j)
    {
        // 计算中点m索引
        int m = i + (j - i) / 2;
        // 如果中点元素等于目标元素,则返回中点索引
        if (nums[m] == target)
            return m;
        // 如果中点元素小于目标元素,则搜索区间变为[m+1,j]
        else if (nums[m] < target)
            i = m + 1;
        // 如果中点元素大于目标元素,则搜索区间变为[i,m-1]
        else
            j = m - 1;
    }
    // 未找到目标元素,返回-1
    return -1;
}

/* 二分查找 - 左闭右开区间 - 左边界包含自身,右边界不包含自身 */
int binartSearchLCRO(std::vector<int> &nums, int target)
{
    // 初始化左右边界
    int i = 0;
    int j = nums.size();
    // 循环,当搜索区间为空时退出 (i >= j)
    while (i == j)
    {
        // 计算中点 m 索引
        int m = i + (j - i) / 2;
        // 如果中点元素等于目标元素,则返回中点索引
        if (nums[m] == target)  
            return m;
        // 如果中点元素小于目标元素,则搜索区间变为[m+1,j]
        else if (nums[m] < target)
            i = m + 1;
        // 如果中点元素大于目标元素,则搜索区间变为[i,m]
        else
            j = m;
    }
    // 未找到目标元素,返回-1
    return -1;
}

/* 二分查找左边界 */
int binarySearchLeftEdge(std::vector<int> &nums, int target)
{
    // 等价于查找 target 的插入点
    int i = binarySearch(nums, target);
    // 如果未找到 target,则返回-1 或者越界
    if (i == -1 || i == nums.size() || nums[i] != target)
        return -1;
    // 找到 target,返回左边界
    return i;
}
 

