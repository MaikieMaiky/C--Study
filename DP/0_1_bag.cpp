// 0 - 1背包问题
// 给定n个物品，每个物品有一个重量和一个价值，给定一个背包的最大承重，问如何选择物品使得背包中的物品总价值最大



/* 0 - 1 背包 暴力搜索 */
#include <vector>
#include <iostream>

using namespace std;


/**
 * @brief 0 - 1 背包问题 暴力搜索
 * 
 * @param weight 物品重量
 * @param value 物品价值
 * @param i 前i个物品
 * @param capacity 背包容量
 * @return int 最大价值
 */
int knapsack(vector<int> &weight, vector<int> &value, int i, int capacity)
{
    // 如果已经选完所有物品，或者背包容量已经为0，返回0
    if (i == 0 || capacity == 0)
        return 0;

    // 分支1：如果当前物品重量大于背包容量，则选择不放入背包
    if (weight[i] > capacity)
        return knapsack(weight, value, i - 1, capacity);

    // 分支2：计算选择当前物品和不选择当前物品的最大价值
    int select = knapsack(weight, value, i - 1, capacity - weight[i]) + value[i];
    int not_select = knapsack(weight, value, i - 1, capacity);
    // 返回价值更大的那个
    return max(select, not_select);
}

/**
 * @brief 0 - 1 背包问题 记忆化搜索
 * 
 * @param weight 物品重量
 * @param value 物品价值
 * @param i 前i个物品
 * @param capacity 背包容量
 * @param memo 记忆化搜索数组
 * @return int 最大价值
 */
int knapsack2(vector<int> &weight, vector<int> &value, int i, int capacity, vector<vector<int>> &memo)
{
    // 如果已经选完所有物品，或者背包容量已经为0，返回0
    if (i == 0 || capacity == 0)
        return 0;

    // 如果已经计算过，直接返回
    if (memo[i][capacity] != -1)
        return memo[i][capacity];

    // 分支1：如果当前物品重量大于背包容量，则选择不放入背包
    if (weight[i] > capacity)
        return memo[i][capacity] = knapsack2(weight, value, i - 1, capacity, memo);

    // 分支2：计算选择当前物品和不选择当前物品的最大价值
    int select = knapsack2(weight, value, i - 1, capacity - weight[i], memo) + value[i];
    int not_select = knapsack2(weight, value, i - 1, capacity, memo);
    // 返回价值更大的那个
    return memo[i][capacity] = max(select, not_select);
}

/**
 * @brief 0 - 1 背包问题 动态规划
 * 
 * @param weight 物品重量
 * @param value 物品价值
 * @param capacity 背包容量
 * @return int 最大价值
 */
int knapsack3(vector<int> &weight, vector<int> &value, int capacity)
{
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= capacity; j++)
        {
            // 如果当前物品重量大于背包容量，则选择不放入背包
            if (weight[i - 1] > j)  
                dp[i][j] = dp[i - 1][j];
            // 否则，选择当前物品和不选择当前物品的最大价值
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
        }

    return dp[n][capacity]; 
}

/**
 * @brief 0 - 1 背包问题 动态规划 空间优化
 * 
 * @param weight 物品重量
 * @param value 物品价值
 * @param capacity 背包容量
 * @return int 最大价值
 */
int knapsack4(vector<int> &weight, vector<int> &value, int capacity)
{
    int n = weight.size();
    vector<int> dp(capacity + 1, 0);

    for (int i = 1; i <= n; i++)
        // 使用逆序遍历,可以避免上一行的数据被覆盖
        for (int j = capacity; j >= weight[i - 1]; j--)
            dp[j] = max(dp[j], dp[j - weight[i - 1]] + value[i - 1]);

    return dp[capacity];
}


// 测试程序
int main()
{
    // 测试动态规划
    vector<int> weight = {2, 3, 4, 5};
    vector<int> value = {3, 5, 6, 7};
    int capacity = 7;
    cout << knapsack3(weight, value, capacity) << endl;
    return 0;
}