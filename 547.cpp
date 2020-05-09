/*
 * @Author: Hata
 * @Date: 2020-05-07 07:53:10
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-07 07:57:42
 * @FilePath: \LeetCode\547.cpp
 * @Description: 
 */

#include <bits/stdc++.h>
#include "UnionFind.h"

class Solution
{
public:
    int findCircleNum(std::vector<std::vector<int>> &M)
    {
        int n = M.size();
        UnionFinder uf(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (M[i][j] == 1)
                    uf.Union(i, j);
            }
        }
        return uf.Count();
    }
};

int main()
{
    Solution s;
    auto M = std::vector<std::vector<int>>{std::vector<int>{1, 1, 0}, std::vector<int>{1, 1, 0}, std::vector<int>{0, 0, 1}};
    std::cout << s.findCircleNum(M) << std::endl;
}