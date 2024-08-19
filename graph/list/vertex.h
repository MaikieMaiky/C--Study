#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <vector>

using namespace std;

/* 顶点类 */
struct Vertex
{
    int val; // 顶点值
    Vertex(int val) : val(val) {}
};

/* 输入值列表 vals ，返回顶点列表 vets */
vector<Vertex *> valsToVets(vector<int> vals) 
{
    vector<Vertex *> vets;
    for (int val : vals) 
    {
        vets.push_back(new Vertex(val));
    }
    return vets;
}

/* 输入顶点列表 vets ，返回值列表 vals */
vector<int> vetsToVals(vector<Vertex *> vets) {
    vector<int> vals;
    for (Vertex *vet : vets) {
        vals.push_back(vet->val);
    }
    return vals;
}

#endif