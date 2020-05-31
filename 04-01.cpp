/*
 * @Author: Hata
 * @Date: 2020-05-31 15:04:20
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-31 15:16:42
 * @FilePath: \LeetCode\04-01.cpp
 * @Description: https://leetcode-cn.com/problems/route-between-nodes-lcci/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    using Table = std::vector<std::vector<int>>;
    Table table;
    bool findWhetherExistsPath(int n, std::vector<std::vector<int>> &graph, int start, int target)
    {
        table = Table(n);
        for (auto &&l : graph)
        {
            table[l.front()].push_back(l.back());
        }
        return dfs(start, target);
    }

    bool dfs(int start, int target)
    {
        if (start == target)
            return true;
        for (auto &&n : table[start])
            if (dfs(n, target))
                return true;
        return false;
    }
};