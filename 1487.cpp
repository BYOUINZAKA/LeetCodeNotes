/*
 * @Author: Hata
 * @Date: 2020-06-29 14:59:45
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-29 15:41:01
 * @FilePath: \LeetCode\1487.cpp
 * @Description: https://leetcode-cn.com/problems/making-file-names-unique/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    template <class V>
    std::vector<std::string> getFolderNames(V &&names)
    {
        std::unordered_map<std::string, int> table;
        std::vector<std::string> res;
        for (auto &&s : std::forward<V>(names))
        {
            auto &&[it, success] = table.try_emplace(s, 0);
            if (success)
            {
                res.push_back(s);
            }
            else
            {
                for (auto &&k = ++(it->second);; ++k)
                {
                    auto &&name = s + "(" + std::to_string(k) + ")";
                    if (table.try_emplace(name, 0).second)
                    {
                        res.push_back(name);
                        break;
                    }
                }
            }
        }
        return res;
    }
};