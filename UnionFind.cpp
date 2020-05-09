/*
 * @Author: Hata
 * @Date: 2020-05-07 07:36:42
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-07 08:02:22
 * @FilePath: \LeetCode\UnionFind.cpp
 * @Description: 
 */

#include "UnionFind.h"

UnionFinder::UnionFinder(std::size_t n) : count(n), parent(n), size(n, 1)
{
    for (auto i = 0; i < n; ++i)
        parent[i] = i;
}

int UnionFinder::Find(int x)
{
    return x == parent[x] ? x : parent[x] = Find(parent[x]);
}

void UnionFinder::Union(int p, int q)
{
    int rootP = Find(p), rootQ = Find(q);
    if (rootP == rootQ)
        return;
    if (size[rootP] > size[rootQ])
    {
        parent[rootQ] = rootP;
        size[rootP] += size[rootQ];
    }
    else
    {
        parent[rootP] = rootQ;
        size[rootQ] += size[rootP];
    }
    count--;
}

bool UnionFinder::Connected(int p, int q)
{
    return Find(p) == Find(q);
}

int UnionFinder::Count() { return this->count; }