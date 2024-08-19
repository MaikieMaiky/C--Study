/* 基于邻接矩阵实现的无向图类 */
#include <iostream>
#include <stdexcept>
#include <vector>

class GraphAdjMat
{

public:
    /* Constructor */
    GraphAdjMat(const std::vector<int> &vertices, const std::vector<std::vector<int>> &edges)
    {
        // 添加顶点
        for (int val : vertices)
            addVertex(val);
        // 添加边
        // 请注意，edges 元素代表顶点索引，即对应 vertices 元素索引
        for (const std::vector<int> &edge : edges)
            addEdge(edge[0], edge[1]);
    }

    /* 获取顶点数量 */    
    int size() const { return vertices.size(); }

    /* 添加顶点 */
    void addVertex(int val)
    {
        int n = vertices.size();
        // 向顶点列表中添加新顶点的值
        vertices.push_back(val);
        // 向邻接矩阵中添加一行
        adjMat.emplace_back(std::vector<int>(n, 0));
        // 向邻接矩阵中添加一列
        for (std::vector<int> &row : adjMat)
            row.push_back(0);
    }

    /* 删除节点 */
    void removeVertex(int index)
    {
        if (index >= vertices.size())
            throw std::out_of_range("Invalid vertex index");
        // 在顶点列表中移出索引为 index 的顶点
        vertices.erase(vertices.begin() + index);
        // 在邻接矩阵中移出索引为 index 的行
        adjMat.erase(adjMat.begin() + index);
        // 在邻接矩阵中移出索引为 index 的列
        for (std::vector<int> &row : adjMat)
            row.erase(row.begin() + index);
    }

    /* 添加边 */
    // 输入参数为顶点值
    void addEdge(int index1, int index2)
    {
        // 处理顶点索引越界
        if (index1 < 0 || index1 >= vertices.size() || index2 < 0 || index2 >= vertices.size())
            throw std::out_of_range("Invalid vertex index");
        // 在邻接矩阵中添加边 在无向图中，邻接矩阵是对称的 即 adjMat[i][j] == adjMat[j][i]
        adjMat[index1][index2] = 1;
        adjMat[index2][index1] = 1;
    }

    /* 删除边 */
    void removeEdge(int index1, int index2)
    {
        // 处理顶点索引越界
        if (index1 < 0 || index1 >= vertices.size() || index2 < 0 || index2 >= vertices.size())
            throw std::out_of_range("Invalid vertex index");
        // 在邻接矩阵中删除边
        adjMat[index1][index2] = 0;
        adjMat[index2][index1] = 0;
    }

    /* 打印邻接矩阵 */
    void printAdjMat() const
    {
        std::cout << "vertices: ";
        // 打印顶点列表
        for (int val : vertices)
            std::cout << val << " ";
        std::cout << std::endl;
        // 打印邻接矩阵
        std::cout << "adjMat: " << std::endl;
        for (const std::vector<int> &row : adjMat)
        {
            for (int val : row)
                std::cout << val << " ";
            std::cout << std::endl;
        }
    
    }

private:
    std::vector<int> vertices;              // 顶点列表,元素代表"顶点值",索引代表"顶点索引"
    std::vector<std::vector<int>> adjMat;   // 邻接矩阵,行列索引对应"顶点索引"
};


int main()
{
    // 创建一个无向图
    GraphAdjMat graph({0, 1, 2, 3, 4}, {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 4}, {2, 3}, {3, 4}});
    // 打印邻接矩阵
    graph.printAdjMat();
    // 删除顶点 2
    graph.removeVertex(2);
    // 打印邻接矩阵
    graph.printAdjMat();
    // 删除边 (0, 1)
    graph.removeEdge(0, 1);
    // 打印邻接矩阵
    graph.printAdjMat();        
}