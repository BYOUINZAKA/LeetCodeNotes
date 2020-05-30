/*
 * @Author: Hata
 * @Date: 2020-05-30 14:37:30
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-30 15:53:32
 * @FilePath: \LeetCode\93.cpp
 * @Description: https://leetcode-cn.com/problems/restore-ip-addresses/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    using Iter = std::string::const_iterator;
    bool check(Iter begin, Iter end)
    {
        int len = end - begin;
        if (len > 3)
            return false;
        int i = 0;
        for (auto it = begin; it != end; ++it)
        {
            i = i * 10 + (*it - '0');
        }
        return *begin != '0' ? i <= 255 : len == 1;
    }

    std::vector<std::string> restoreIpAddresses(std::string &s)
    {
        std::vector<std::string> res;
        if (s.size() == 0 || s.size() < 4)
            return res;
        std::vector<std::pair<Iter, Iter>> path;
        dfs(s.cbegin(), s.cend(), path, res);
        return res;
    }

    void dfs(Iter pos, Iter end, std::vector<std::pair<Iter, Iter>> &path, std::vector<std::string> &res)
    {
        int maxlen = (4 - path.size()) * 3;
        if (end - pos > maxlen)
            return;
        if (path.size() == 4 && pos == end)
        {
            std::string ans;
            for (auto &&i : {0, 1, 2, 3})
            {
                std::for_each(path[i].first, path[i].second, [&ans](auto &&c) {
                    ans.push_back(c);
                });
                if (i != 3)
                    ans.push_back('.');
            }
            res.push_back(ans);
            return;
        }
        for (auto it = pos; it != end && it != pos + 3; ++it)
        {
            if (check(pos, it + 1))
            {
                path.emplace_back(pos, it + 1);
                dfs(it + 1, end, path, res);
                path.pop_back();
            }
        }
    }
};