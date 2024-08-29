#include "../list/vertex.h"
#include <queue>
#include <unordered_set>


#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>

class GraphAdjList
{
public:
    // 邻接表,key: 顶点,value: 该顶点的所有邻接顶点
    std::unordered_map<Vertex *, vector<Vertex *>> adjList;

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
};

/* 广度优先遍历 */
// 使用邻接表来表示图，以便获取指定顶点的所有邻接顶点
vector<Vertex *> graphBFS(GraphAdjList &graph, Vertex *startVet) 
{
    // 顶点遍历序列
    vector<Vertex *> res;
    // 哈希集合，用于记录已被访问过的顶点
    unordered_set<Vertex *> visted = {startVet};
    // 广度优先遍历队列
    queue<Vertex *> que;
    que.push(startVet);
    // 以顶点 vet 为起点,循环直至访问完所有顶点
    while (!que.empty())
    {
        Vertex *vet = que.front();
        que.pop();          // 队首顶点出队
        res.push_back(vet); // 记录访问顶点
        // 遍历该顶点的所有邻接节点
        for (auto *adjVet : graph.adjList[vet])
        {
            if (visted.count(adjVet))
                continue;           // 如果邻接节点已被访问过,则跳过
            que.push(adjVet);       // 只入队未被访问过的邻接节点
            visted.insert(adjVet);  // 标记邻接节点为已访问
        } // end of for
    } // end of while
    // 返回遍历结果
    return res;
}\


int main() 
{
    // 创建顶点
    Vertex *v1 = new Vertex(1);
    Vertex *v2 = new Vertex(2);
    Vertex *v3 = new Vertex(3);
    Vertex *v4 = new Vertex(4);
    Vertex *v5 = new Vertex(5);

    // 创建边
    vector<vector<Vertex *>> edges = 
    {
        {v1, v2},
        {v1, v3},
        {v2, v4},
        {v3, v4},
        {v4, v5}
    };

    // 创建图
    GraphAdjList graph(edges);

    // 打印图的邻接表
    graph.print();

    // 执行广度优先遍历
    vector<Vertex *> bfsResult = graphBFS(graph, v1);

    // 打印广度优先遍历结果
    std::cout << "BFS result:" << std::endl;
    for (Vertex *v : bfsResult)
        std::cout << v->val << " ";
    std::cout << std::endl;

    // 释放顶点内存
    delete v1;
    delete v2;
    delete v3;
    delete v4;
    delete v5;

    return 0;
}