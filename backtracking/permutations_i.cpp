// 全排列问题 - 回溯算法的经典应用
// 定义是在给定一个集合（如一个数组或字符串）的情况下，找出其中元素的所有可能的排列
// 特别注意:本体不会出现重复元素,因此不需要考虑重复元素的情况
#include <vector>
#include <iostream>

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

    // 遍历选择列表
    for (int i = 0; i < choices.size(); i++)
    {
        int choice = choices[i];
        // 剪枝: 剪去带有重复元素的排列
        if (!selected[i])
        {
            // 尝试 - 做出选择,更新状态
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

vector<vector<int>> permutations(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    backtrack(state, nums, res, selected);
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> res = permutations(nums);
    // 输出结果
    for (const auto &vec : res)
    {
        for (int num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}