// n皇后问题
// 根据国际象棋的规则，皇后可以攻击与同处一行、一列或一条斜线上的棋子。
// 给定 n 个皇后和一个 n * n 大小的棋盘，寻找使得所有皇后之间无法相互攻击的摆放方案

// 分析
// 1. 行剪枝 
// 2. 列剪枝
// 3. 对角线剪枝

// 策略
// 1. 逐行放置皇后
// 2. 使用bool数组记录列
// 3. 根据col +- row 是否为恒定值来判断主副对角线, 使用两个bool数组来记录主副对角线


// n维方阵中:
// row - col 范围[-(n-1), n-1]
// row + col 范围[0, 2n-2]

#include <vector>
#include <string>
#include <iostream>

using namespace std;


/* 
 * @brief 回溯函数
 * @param state 当前状态
 * @param row 当前行
 * @param n 总行数
 * @param res 结果集
 * @param cols 列
 * @param main_diag 主对角线
 * @param anti_diag 副对角线
 */
void backtrack(vector<vector<string>> &state, int row, int n, vector<vector<vector<string>>> &res,
               vector<bool> &cols, vector<bool> &main_diag, vector<bool> &anti_diag)
{
    // 所有行都放置完毕
    if (row == n)
    {
        res.push_back(state);
        return;
    }

    // 遍历所有列
    for (int col = 0; col < n; ++col)
    {
        // 剪枝 判断列 主对角线 副对角线是否冲突
        if (cols[col] || main_diag[row - col + n - 1] || anti_diag[row + col])
            continue;
        
        // 计算主对角线和副对角线的索引
        int diag1 = row - col + n - 1;
        int diag2 = row + col;

        // 尝试
        // 将格子标记为皇后
        state[row][col] = "Q";
        cols[col] = true;
        main_diag[diag1] = true;
        anti_diag[diag2] = true;

        // 放置下一行
        backtrack(state, row + 1, n, res, cols, main_diag, anti_diag);

        // 回退
        // 将格子恢复为空位
        state[row][col] = "#";
        cols[col] = false;
        main_diag[diag1] = false;
        anti_diag[diag2] = false;
    }
}

/* 
 * @brief 解决n皇后问题
 * @param n 皇后数量
 * @return 所有可能的解决方案
 */
vector<vector<vector<string>>> solveNQueens(int n)
{
    // 初始化状态 n*n 的棋盘 其中"Q"代表皇后 "#"代表空位
    vector<vector<string>> state(n, vector<string>(n, "#"));
    // 初始化列 主对角线 副对角线的皇后记录数组
    vector<bool> cols(n, false);
    vector<bool> main_diag(2 * n - 1, false);
    vector<bool> anti_diag(2 * n - 1, false);
    // 结果集
    vector<vector<vector<string>>> res;

    // 回溯
    backtrack(state, 0, n, res, cols, main_diag, anti_diag);

    return res;
}

int main()
{
    int n = 4;
    vector<vector<vector<string>>> res = solveNQueens(n);
    // 打印结果
    for (auto &solution : res)
    {
        cout << "Solution:" << endl;
        for (auto &row : solution)
        {
            for (auto &cell : row)
                cout << cell << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}