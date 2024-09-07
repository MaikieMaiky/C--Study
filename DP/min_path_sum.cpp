// 最小路径和 作为动态规划解题步骤的例题
// 通常动态规划解题步骤：描述决策，定义状态，建立DP表，推导状态转移方程，确定边界条件等

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

/* Brute force search */
int minPathSumDFS(vector<vector<int>> &grid, int i, int j) 
{
    // 若为左上角单元格，则终止搜索
    if (i == 0 && j == 0) 
        return grid[0][0];

    // 若行列索引越界，则返回 +∞ 代价
    if (i < 0 || j < 0) 
        return INT_MAX;

    // 计算从左上角到 (i-1, j) 和 (i, j-1) 的最小路径代价
    int up = minPathSumDFS(grid, i - 1, j);
    int left = minPathSumDFS(grid, i, j - 1);

    // 返回从左上角到 (i, j) 的最小路径代价
    return min(left, up) != INT_MAX ? min(left, up) + grid[i][j] : INT_MAX;
}


/* memory search to avoid repeat calculation */
int minPathSumDFSMem(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &mem) 
{
    // 若为左上角单元格，则终止搜索
    if (i == 0 && j == 0) 
        return grid[0][0];

    // 若已搜索过，则直接返回
    if (mem[i][j] != -1) 
        return mem[i][j];

    // 计算从左上角到 (i-1, j) 和 (i, j-1) 的最小路径代价
    int up = minPathSumDFSMem(grid, i - 1, j, mem);
    int left = minPathSumDFSMem(grid, i, j - 1, mem);

    // 记录结果至 mem[i][j]
    mem[i][j] = min(left, up) != INT_MAX ? min(left, up) + grid[i][j] : INT_MAX;

    // 返回结果
    return mem[i][j];
}


/* Dynamic programming */
int minPathSumDP(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    // initialize dp array
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = grid[0][0];

    // fill first row
    for (int j = 1; j < m; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j];

    // fill first column
    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    // fill the rest
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];

    // return result
    return dp[n - 1][m - 1];
}


/* memory optimization */
int minPathSumDP2(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    // initialize dp array - only one row
    vector<int> dp(m);

    // fill first element
    dp[0] = grid[0][0];

    // fill first row
    for (int j = 1; j < m; j++)
        dp[j] = dp[j - 1] + grid[0][j];

    // fill the rest
    for (int i = 1; i < n; i++)
    {
        // fill first element
        dp[0] = dp[0] + grid[i][0];

        // fill first row
        for (int j = 1; j < m; j++)
            dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
    }

    // return result
    return dp[m - 1];
}

int main()
{
    // 测试用例

    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    // print result
    cout << "The minimum path sum is: " << minPathSumDP2(grid) << endl;
    
    return 0;
}