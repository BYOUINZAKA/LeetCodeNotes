/*
 * @Author: Hata
 * @Date: 2020-05-21 12:04:42
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-21 13:37:47
 * @FilePath: \LeetCode\1443.cpp
 * @Description: https://leetcode-cn.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
 */
#include <bits/stdc++.h>

/*
class Solution
{
    std::unordered_map<int, std::vector<int>> tree;
    std::vector<bool> hasApple;

public:
    int minTime(int n, std::vector<std::vector<int>> &edges, std::vector<bool> &hasApple)
    {
        this->hasApple = hasApple;
        for (auto &&e : edges)
        {
            tree[e.front()].push_back(e.back());
        }
        return dfs(0).first;
    }

    std::pair<int, bool> dfs(int node)
    {
        auto childs = tree[node];
        bool route = hasApple[node];
        int res = 0;
        for (auto &&i : childs)
        {
            auto n = dfs(i);
            route |= n.second;
            if (n.second)
                res += n.first + 2;
        }
        return {res, route};
    }
};
*/

/*
class Solution
{
    std::vector<std::vector<int>> edges;
    std::vector<bool> hasApple;

public:
    using Iter = std::vector<std::vector<int>>::iterator;
    int minTime(int n, std::vector<std::vector<int>> &edges, std::vector<bool> &hasApple)
    {
        this->hasApple = hasApple;
        this->edges = edges;
        return dfs(0, (this->edges).begin(), (this->edges).end()).first;
    }

    std::pair<int, bool> dfs(int node, Iter begin, Iter end)
    {
        bool route = hasApple[node];
        int res = 0;
        for (auto it = begin; it != end; ++it)
        {
            it = std::find_if(it, end, [&node](const auto &v) {
                return v.front() == node || v.back() == node;
            });
            if (it != end)
            {
                std::pair<int, bool> n;
                if (it->front() == node)
                    n = dfs(it->back(), it + 1, end);
                else if (it->back() == node)
                    n = dfs(it->front(), it + 1, end);
                route |= n.second;
                if (n.second)
                    res += n.first + 2;
            }
            else
                break;
        }
        return {res, route};
    }
};
*/

class Solution
{

public:
    int minTime(int n, std::vector<std::vector<int>> &edges, std::vector<bool> &hasApple)
    {
        
    }
};