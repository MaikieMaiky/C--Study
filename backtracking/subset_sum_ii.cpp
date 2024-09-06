// 子集和 II
// 给定一个数组,包含重复元素,每个数组元素只能使用一次,求所有和为target的子集

// 本体相较于全集和问题有比较巧妙的剪枝方法
// 1. 对choices进行排序
// 2. 当选择重复时，一次剪去后面所有的分支
// 3. 由于排序后的相同元素相邻,所以可以通过相邻元素比较来剪枝


#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


void backtrack(vector<int> &state, int target, int start, vector<int> &choices, vector<vector<int>> &res)
{
    // 子集和等于target时，记录解
    if (target == 0)
    {
        res.push_back(state);
        return;
    }

    // 遍历所有选择
    // 剪枝1: 从start开始遍历,避免产生重复子集
    for (size_t i = start; i < choices.size(); i++)
    {
        // 剪枝2: 当总和大于目标值时，停止遍历
        if (target - choices[i] < 0)
            break;
        // 剪枝3: 当选择重复时，跳过
        if (i > start && choices[i] == choices[i - 1])
            continue;
        // 尝试
        state.push_back(choices[i]);
        // 进行回溯
        // 剪枝4: 这里i+1, 表示每个元素只能使用一次
        backtrack(state, target - choices[i], i + 1, choices, res);
        // 回退
        state.pop_back();
    }
}

vector<vector<int>> subsetSumII(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    vector<int> state;
    // 对choices进行排序
    sort(nums.begin(), nums.end());
    backtrack(state, target, 0, nums, res);
    return res;
}

int main()
{
    vector<int> nums = {2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> res = subsetSumII(nums, target);
    for (auto &vec : res)
    {
        for (auto &num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
