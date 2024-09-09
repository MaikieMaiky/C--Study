// 零钱兑换问题2 :区别于零钱兑换问题1, 这里需要求解的是有多少种组合方式


// 当前状态的组合数量 = 不选当前硬币的组合数量 + 选当前硬币的组合数量
// 状态转移方程: dp[i][a] = dp[i - 1][a] + dp[i][a - coins[i - 1]]

// 当目标金额为0时, 无需选择硬币就可以凑出目标金额, 因此将第一列初始化为1
// 当硬币数量为0时, 无法选择硬币, 因此将第一行初始化为0

#include <vector>
#include <iostream>

using namespace std;

int coinChange2(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    // 初始化 第一列为 1
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int a = 1; a <= amount; a++)
        {
            // 如果当前硬币大于目标金额, 则只有不选当前硬币一种情况
            if (coins[i - 1] > a)
            {
                dp[i][a] = dp[i - 1][a];
            }
            // 否则, 当前状态的组合数量 = 不选当前硬币的组合数量 + 选当前硬币的组合数量
            else
            {
                dp[i][a] = dp[i - 1][a] + dp[i][a - coins[i - 1]];
            }
        }
    }
    return dp[n][amount];
}

// 空间优化 去掉i - 1的 -1 就可以
int coinChange2_opt(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int a = 1; a <= amount; a++)
        {
            if (coins[i - 1] > a)
                dp[a] = dp[a];
            else
                dp[a] = dp[a] + dp[a - coins[i - 1]];
        }
    return dp[amount];
}
// 测试
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << coinChange2(coins, amount) << endl;
    cout << coinChange2_opt(coins, amount) << endl;
    return 0;
}