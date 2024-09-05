// 全排列问题
// 本体有重复元素,因此需要考虑重复元素的情况
// 我们使用剪枝的方式来提前停止搜索
// 这题我们使用哈希集合来记录该轮选择列表中已经尝试过的元素

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

// 需要添加一个额外的参数 selected，用于记录当前选择列表中已经使用过的元素
void backtrack(vector<int> &state, vector<int> &choices, vector<vector<int>> &res, vector<bool> &selected)
{
    // 当状态长度等于选择列表长度时，记录解
    if (state.size() == choices.size())
    {
        res.push_back(state);
        return;
    }

    // 遍历选择列表 可以这么理解:duplicated 记录当前层级已经选择过的元素 防止在切换到当前层级其他元素时重复选择
    // 影响的是本层,也就是for循环这个外层,而不是backtrack这个递归调用栈
    // 而由于每次进入新的递归层级时，duplicated 集合都会重新初始化，所以允许在新的位置上重新考虑之前用过的数字。
    unordered_set<int> duplicated;
    for (int i = 0; i < choices.size(); i++)
    {
        int choice = choices[i];
        // 剪枝: 不允许重复选择元素 和 不允许重复选择相等元素
        if (!selected[i] && duplicated.find(choice) == duplicated.end())
        {
            // 尝试 - 做出选择,更新状态
            duplicated.emplace(choice); // 记录该轮已经尝试过的元素
            state.push_back(choice);
            selected[i] = true;
            // 进行下一轮选择
            backtrack(state, choices, res, selected);

            // 回退 - 撤销选择,恢复到之前的状态
            state.pop_back();
            selected[i] = false;
        }
    }
}

/* 全排列II */
vector<vector<int>> permutationsII(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    backtrack(state, nums, res, selected);
    return res;
}

int main()
{
    vector<int> nums = {1, 1, 2, 3};
    vector<vector<int>> res = permutationsII(nums);
    for (auto &vec : res)
    {
        for (auto &num : vec)
            cout << num << " ";
        cout << endl;
    }
}

