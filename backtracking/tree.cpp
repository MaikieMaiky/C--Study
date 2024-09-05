// 使用同一目录下的模板框架编写以下题目的回溯代码
// 在二叉树中搜索所有值为7的节点，请返回根节点到这些节点的路径，并要求路径中不包含值为3的节点。

#include <vector>
    
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* 判断是否有解 */
bool isSolution(vector<TreeNode *> &state) 
{
    return !state.empty() && state.back()->val == 7;
}

/* 记录解 */
void recordSolution(vector<TreeNode *> &state, vector<vector<TreeNode *>> &res) 
{
    res.push_back(state);
}


/* 判断选择是否有效 */  
bool isValid(vector<TreeNode *> &state, TreeNode *choice) 
{
    return choice != nullptr && choice->val != 3;
}

/* 尝试 */
void makeChoice(vector<TreeNode *> &state, TreeNode *choice) 
{
    state.push_back(choice);
}

/* 回退 */
void undoChoice(vector<TreeNode *> &state, TreeNode *choice) 
{
    state.pop_back();
}

/* 回溯 */
void backtrack(vector<TreeNode *> &state, vector<TreeNode *> &choices, vector<vector<TreeNode *>> &res) 
{
    // 判断是否为解
    if (isSolution(state)) 
    {
        recordSolution(state, res);
    }

    // 遍历所有选择
    for (TreeNode *choice : choices) 
    {
        // 剪枝: 判断选择是否有效
        if (isValid(state, choice)) 
        {
            // 尝试
            makeChoice(state, choice);
            // 进行回溯
            // 获取所有可能的选择
            vector<TreeNode *>nextChoices = {choice->left, choice->right};
            backtrack(state, nextChoices, res);
            // 回退
            undoChoice(state, choice);
        }
    }
}
