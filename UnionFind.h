/*
 * @Author: Hata
 * @Date: 2020-05-07 07:35:45
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-07 08:06:16
 * @FilePath: \LeetCode\UnionFind.h
 * @Description: 
 */

#include <vector>

class UnionFinder
{
    std::size_t count;
    std::vector<int> parent;
    std::vector<int> size;

public:
    UnionFinder(std::size_t n);
    int Find(int x);
    void Union(int p, int q);
    bool Connected(int p, int q);
    int Count();
};