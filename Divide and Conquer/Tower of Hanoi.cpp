#include <iostream>
#include <vector>

void printTowers(const std::vector<int>& A, const std::vector<int>& B, const std::vector<int>& C) {
    std::cout << "A: ";
    for (int disk : A) std::cout << disk << " ";
    std::cout << "\nB: ";
    for (int disk : B) std::cout << disk << " ";
    std::cout << "\nC: ";
    for (int disk : C) std::cout << disk << " ";
    std::cout << "\n\n";
}

void move(std::vector<int>& src, std::vector<int>& tar, char srcName, char tarName)
{
    int disk = src.back();
    tar.push_back(disk);
    src.pop_back();
    std::cout << disk << ": " << srcName << " -> " << tarName << std::endl;
}

void dfs(int n, std::vector<int>& src, std::vector<int>& tar, std::vector<int>& buffer,
         char srcName, char tarName, char bufferName)
{
    if (n == 1)
    {
        move(src, tar, srcName, tarName);
        return;
    }
    dfs(n - 1, src, buffer, tar, srcName, bufferName, tarName);
    move(src, tar, srcName, tarName);
    dfs(n - 1, buffer, tar, src, bufferName, tarName, srcName);
}

/**
 * 汉诺塔问题解决方案
 * @param n 圆盘的数量
 */
void hanoi(int n)
{
    std::vector<int> A, B, C;
    for (int i = n; i > 0; i--)
        A.push_back(i);
    
    std::cout << "Initial state:" << std::endl;
    printTowers(A, B, C);
    
    dfs(n, A, C, B, 'A', 'C', 'B');
    
    std::cout << "Final state:" << std::endl;
    printTowers(A, B, C);
}

// 汉诺塔问题 分治策略
int main()
{
    
    hanoi(3);
    return 0;
}