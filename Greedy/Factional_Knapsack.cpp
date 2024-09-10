// 分数背包问题
// 题目内容: 给定n个物品，每个物品有重量和价值，在给定背包的容量，
// 问在不超过背包容量的前提下，背包内物品的最大价值是多少

// 我们使用贪心算法来解决这个问题
// 解题思路: 1. 按照性价比排序 2. 尽可能多的装性价比高的物品 3. 如果背包容量不够，则将物品的一部分装入背包

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 物品结构体
struct Item 
{
    int weight;
    int value;

    // 构造函数
    Item(int weight, int value) : weight(weight), value(value) {}
};

/* 分数背包: 贪心 */
double fractionalKnapsack(vector<int> &weight, vector<int> &value, int capacity)
{
    // 创建一个物品向量
    vector<Item> items;
    for (size_t i = 0; i < weight.size(); i++)
        items.push_back(Item(weight[i], value[i]));
    
    // 按照性价比排序
    // 使用lambda表达式，提供了比较函数
    sort(items.begin(), items.end(), [](Item &a, Item &b)
    {
        return a.value * b.weight > b.value * a.weight;
    });

    // 初始化最大价值
    double maxValue = 0.0;

    // 遍历物品
    for (const auto &item : items)
    {
        // 如果背包容量大于物品重量，则将物品全部装入背包
        if (capacity >= item.weight)
        {
            maxValue += item.value;
            capacity -= item.weight;
        }
        // 如果背包容量小于物品重量，则将物品的一部分装入背包 容量归零 跳出循环
        else
        {
            maxValue += (double)item.value / item.weight * capacity;
            break;
        }
    }

    return maxValue;
}


// test
int main()
{
    vector<int> weight = {10, 20, 30};
    vector<int> value = {60, 100, 120};
    int capacity = 50;
    // 正确的结果应当是 240
    cout << fractionalKnapsack(weight, value, capacity) << endl;
    
    return 0;
}