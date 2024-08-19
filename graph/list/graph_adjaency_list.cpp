/* 基于邻接表实现的无向图表 */
// 注意:这里使用动态数组来存储邻接表，而不是链表
// 注意:使用哈希表来表示邻接表,key为顶点,value为顶点的邻接顶点列表
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include "vertex.h"

class GraphAdjList
{
public:

    /* 构造函数 */
    GraphAdjList(const vector<vector<Vertex *>> &edges) 
    {
        // 添加所有顶点和边
        for (const vector<Vertex *> &edge : edges) 
        {
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0], edge[1]);
        }
    }

    /* 析构函数 */
    ~GraphAdjList() 
    {
        // 释放所有顶点
        for (auto &adj : adjList) 
        {
            delete adj.first;
        }
    }

    /* 在 vector 中删除指定的节点 */
    void remove(vector<Vertex *> &vec, Vertex *vet)
    {
        for (auto it = vec.begin(); it != vec.end(); it++)
        {
            if (*it == vet)
            {
                vec.erase(it);
                break;
            }
        }
    }

    /* 获取顶点数量 */
    int size() const { return adjList.size(); }

    /* 添加顶点 */
    void addVertex(Vertex *vet) 
    {
        // 如果顶点已经存在，则直接返回
        if (adjList.count(vet))
            return;
        // 否则，添加顶点
        adjList[vet] = vector<Vertex *>();
    }

    /* 删除顶点 */
    void removeVertex(Vertex *vet) 
    {
        // 如果顶点不存在，则直接返回
        if (!adjList.count(vet))
            throw std::invalid_argument("Vertex not found");
        // 在邻接表中删除顶点 vet 对应的链表
        adjList.erase(vet);
        // 遍历其他顶点的链表,删除所有包含 vet 的边
        for (auto &adj : adjList) 
        {
            remove(adj.second, vet);
        }
    }

    /* 添加边 */
    void addEdge(Vertex *vet1, Vertex *vet2) 
    {
        // 如果顶点不存在，则抛出异常
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw std::invalid_argument("Vertex not found");
        // 添加边 vet1 - vet2
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }

    /* 删除边 */
    void removeEdge(Vertex *vet1, Vertex *vet2) 
    {
        // 如果顶点不存在，则抛出异常
        if (!adjList.count(vet1) || !adjList.count(vet2))
            throw std::invalid_argument("Vertex not found");
        // 删除边 vet1 - vet2
        remove(adjList[vet1], vet2);
        remove(adjList[vet2], vet1);
    }

    /* 打印邻接表 */
    void print()
    {
        std::cout << "GraphAdjList:" << std::endl;
        for (auto &adj : adjList)
        {
            const auto &key = adj.first;
            const auto &vec = adj.second;
            std::cout << key->val << " : ";
            for (const auto &vet : vec)
            {
                std::cout << vet->val << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    // 邻接表,key: 顶点,value: 该顶点的所有邻接顶点
    std::unordered_map<Vertex *, vector<Vertex *>> adjList;
};



int main()
{
    // 顶点列表
    vector<Vertex *> vets = valsToVets({1, 2, 3, 4, 5});
    // 边列表
    vector<vector<Vertex *>> edges = 
    {
        {vets[0], vets[1]},
        {vets[0], vets[2]},
        {vets[0], vets[3]},
        {vets[1], vets[2]},
        {vets[1], vets[3]},
        {vets[2], vets[3]},
        {vets[2], vets[4]},
        {vets[3], vets[4]}
    };
    // 创建图
    GraphAdjList graph(edges);
    // 打印图
    graph.print();
    // 删除顶点 3
    graph.removeVertex(vets[2]);
    // 打印图
    graph.print();
    // 添加边 1 - 5
    graph.addEdge(vets[0], vets[4]);
    // 添加节点 6
    graph.addVertex(new Vertex(6));
    // 打印图
    graph.print();    
}