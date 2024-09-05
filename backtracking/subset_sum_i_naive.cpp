// 子集和问题 - 无重复元素的情况
// 给定一个正整数数组 nums 和一个目标正整数 target ，请找出所有可能的组合，使得组合中的元素和等于 target 。
// 给定数组无重复元素，每个元素可以被选取多次。请以列表形式返回这些组合，列表中不应包含重复组合。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 开始优化代码
// 剪枝2: 对choices进行排序，如果当前选择大于target,则停止遍历 因为后面的选择更大，不可能满足条件

void backtrack(vector<int> &state, int target, int start, vector<int> &choices, vector<vector<int>> &res)
{
    // 当总和等于目标值时，记录解
    if (target == 0)
    {
        res.push_back(state);
        return;
    }

    // 遍历所有选择
    // 剪枝2: 从start开始遍历,避免产生重复子集
    for (size_t i = start; i < choices.size(); i++)
    {
        int choice = choices[i];
        // 剪枝1: 当总和大于目标值时，停止遍历
        if (target - choice < 0)
            break;
        // 尝试
        state.push_back(choice);
        // 进行回溯
        backtrack(state, target - choice, i, choices, res);
        // 回退
        state.pop_back();
    }
}

vector<vector<int>> subsetSumI(vector<int> &nums, int target)
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
    vector<int> nums = {3, 4, 5};
    int target = 9;
    vector<vector<int>> res = subsetSumI(nums, target);
    for (auto &vec : res)
    {
        for (auto &num : vec)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}
