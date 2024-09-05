// 本文件提炼回溯的"尝试 回退 剪枝"的框架作为模板
#include <vector>

/* 回溯算法框架 */
// 参数state表示当前状态,choices表示当前可以作出的选择
void backtrack(State state, std::vector<Choice *> &choices, std::vector<Choice *> &res) 
{
    // 判断是否为解
    if (isSolution(state)) 
    {
        // 记录解
        recordSolution(state, res);
        // 不再继续探索
        return;
    }

    // 遍历所有选择
    for (Choice choice : choices) 
    {
        // 剪枝: 判断选择是否有效
        if (isInvalid(state, choice)) 
        {
            // 尝试
            makeChoice(state, choice);
            // 进行回溯
            backtrack(state, choices, res);
            // 回退
            undoChoice(state, choice);
        }

        
    }
}
