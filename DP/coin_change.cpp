// 完全背包问题变种 - 硬币兑换问题
// 给定不同面额的硬币和一个总金额, 计算凑成总金额所需的最少硬币数

// 可以这么理解,将每个硬币的价值看作1,那么我们就只需要找到最少的硬币数
// 这样子,我们就可以使用完全背包问题的思路来解决这个问题

// 注意这里我们需要刚好将硬币凑成总金额,而背包问题要求的是不超过背包容量下的解

// 状态表示: dp[i][j] 表示前i个硬币凑成j所需的最少硬币数
// 状态转移: dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]] + 1)
// 初始化: dp[0][0] = 0, 其余为无穷大
// 返回值: dp[n][amount]

// 边界条件
// 1. 当总金额为0时, 所需硬币数为0 所以dp列表的第一列为0
// 2. 当硬币数为0的时候, 其为无效解, 所以dp列表的第一行其余为无穷大

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/**
 * @brief 硬币兑换问题
 * 
 * @param coins 存放的是硬币的面额
 * @param amount 需要凑成的总金额
 * @return int 返回的是最少硬币数
 */
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j <= amount; ++j)
        {
            // 如果硬币金额超过当前目标金额, 则不选硬币 i
            if (j < coins[i])
                continue;
            // 如果硬币 i 被选择, 则 dp[j] 的值取决于 dp[j - coins[i]] 的值
            if (dp[j - coins[i]] != INT_MAX)
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    // 如果dp[amount]等于INT_MAX，说明无法用给定硬币凑出目标金额
    // 因为在初始化时，我们将dp数组除了dp[0]外的所有元素都设置为INT_MAX
    // 如果经过所有可能的硬币组合后，dp[amount]仍然是INT_MAX
    // 这意味着没有任何硬币组合能够凑出目标金额
    // 在这种情况下，我们返回-1表示无解
    // 否则，返回dp[amount]，即凑出目标金额所需的最少硬币数
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

/* 零钱兑换：动态规划 */
int coinChangeDP(vector<int> &coins, int amt) {
    int n = coins.size();
    int MAX = amt + 1;
    // 初始化 dp 表
    vector<vector<int>> dp(n + 1, vector<int>(amt + 1, 0));
    // 状态转移：首行首列
    for (int a = 1; a <= amt; a++) {
        dp[0][a] = MAX;
    }
    // 状态转移：其余行和列
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                // 若超过目标金额，则不选硬币 i
                dp[i][a] = dp[i - 1][a];
            } else {
                // 不选和选硬币 i 这两种方案的较小值
                dp[i][a] = min(dp[i - 1][a], dp[i][a - coins[i - 1]] + 1);
            }
        }
    }
    return dp[n][amt] != MAX ? dp[n][amt] : -1;
}

// 测试
int main()
{
    vector<int> coins = {5, 7, 8};
    int amount = 11;
    cout << coinChangeDP(coins, amount) << endl;
    return 0;
}