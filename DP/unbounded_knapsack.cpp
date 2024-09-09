// 完全背包问题
// 完全背包问题与0-1背包问题的区别在于，完全背包问题中的物品可以重复选择

// 因此我们需要将状态转移方程进行以下修改
// 1. 不放入物品i: dp[i][c] = dp[i - 1][c]
// 2. 放入物品i: dp[i][c] = dp[i][c - weight[i]] + value[i] -> 注意:这里i 是不需要-1的，因为下一次可以继续决定选或者不选

#include <vector>
#include <iostream>
using namespace std;

/* 完全背包问题 - 动态规划 */
int unboundedKnapsack(vector<int> &weight, vector<int> &value, int capacity)
{
    int n = weight.size();
    // initialize dp array
    vector<int> dp(capacity + 1, 0);

    for (int i = 1; i <= n; i++)
        for (int c = 1; c <= capacity; c++)
        {
            // 如果超过背包容量,则不选物品i
            if (weight[i - 1] > c)
                dp[c] = dp[c];
            // 否则,选择 放入或者不放入物品i的最大值
            else
                dp[c] = max(dp[c], dp[c - weight[i - 1]] + value[i - 1]);
        }
    return dp[capacity];
}

// 测试程序
int main()
{
    vector<int> weight = {1, 2, 3};
    vector<int> value = {6, 10, 12};
    int capacity = 5;
    int res = unboundedKnapsack(weight, value, capacity);
    cout << res << endl;
    return 0;
}