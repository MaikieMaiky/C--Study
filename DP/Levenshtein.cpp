// 编辑距离问题
// 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

// 使用场景: 字符串的相似度判断, 搜索引擎的单词纠错, DNA序列的相似度判断

// 暴力搜索分析
// 四种情况 1.不变 2.删除 3.添加 4.替换

// 分析发现,我们需要的是执行操作前的四种情况的最小次数再加上1
// 当前状态由前4种状态的最小值决定
// 因此我们可以尝试推导其状态转移方程


// Source长度为i Target长度为j
// 1. 相等 DP[i][j] = DP[i - 1][j - 1]
// 2. 删除 DP[i][j] = DP[i - 1][j] + 1
// 3. 添加 DP[i][j] = DP[i][j - 1] + 1
// 4. 替换 DP[i][j] = DP[i - 1][j - 1] + 1
// min(1, 2, 3, 4)

// DP列表初始化
// 当Target为空时,最小步数为Source的长度
// 当Source为空时,最小步数为Target的长度
// 因此DP[i][0] = i, DP[0][j] = j



#include <vector>
#include <string>
#include <algorithm>
#include <iostream>


using namespace std;


/**
 * @brief 编辑距离 动态规划
 * 
 * @param source 源字符串
 * @param target 目标字符串
 * @return int   编辑距离
 */
int levenshtein(string &source, string &target)
{
    // get size
    int m = source.size();
    int n = target.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // initialize DP Array
    // col
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    // row
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;
    
    // fill DP Array
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            // if current char is same, no operation needed
            if (source[i - 1] == target[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            // if current char is different, we need to do one operation 添加/删除/替换
            else
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }

    return dp[m][n];
}

// TODO: 现在开始进行对动态规划代码的空间优化
// 我发现,当前状态与二位数组上方,左方和左上方的状态有关
// 1. 使用正序遍历, 发现左上角的状态被破坏, 因此不可行
// 2. 使用倒序遍历, 无法提前更新左方的状态, 因此也不可行
// 结合之前的正序遍历和倒序遍历的思路, 我们可以使用一个变量来保存左上角的状态, 进而可以使用正序遍历

int levenshtein_opt(string &source, string &target)
{
    int m = source.size();
    int n = target.size();
    int left_up = 0;

    // initialize DP Array
    vector<int> dp(n + 1, 0);
    for (int j = 0; j <= n; j++)
        dp[j] = j;
    
    // fill DP Array
    for (int i = 1; i <= m; i++)
    {
        // 保存左上角的状态
        left_up = dp[0];
        // 初始化左边界
        dp[0] = i;
        // 状态转移
        for (int j = 1; j <= n; j++)
        {
            int temp = dp[j];
            // if current char is same, no operation needed
            if (source[i - 1] == target[j - 1])
                dp[j] = left_up; // left_up = dp[i - 1][j - 1] 这里指该字符不变
            else
                dp[j] = min({left_up, dp[j], dp[j - 1]}) + 1; // 这里的left_up 指的是替换操作
            // 更新左上角的状态
            left_up = temp;
        }
    }

    return dp[n];
}


// 测试
int main()
{
    // horse -> ros
    string source = "horse";
    string target = "ros";

    cout << "The edit distance between " << source << " and " << target << " is: " << levenshtein_opt(source, target) << endl;

    return 0;
}