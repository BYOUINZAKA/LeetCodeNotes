/*
 * @Author: Hata
 * @Date: 2020-05-25 20:02:43
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-29 17:53:35
 * @FilePath: \LeetCode\1239.cpp
 * @Description: https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    using Iter = std::vector<std::string>::const_iterator;

    int maxLength(std::vector<std::string> &arr)
    {
        return dfs(arr.cbegin(), arr.cend(), 0);
    }

    int dfs(Iter ptr, Iter end, int table)
    {
        if (ptr == end)
        {
            return 0;
        }
        auto temp = table;
        if (check(*ptr, temp))
        {
            int left = ptr->length() + dfs(ptr + 1, end, temp);
            int right = dfs(ptr + 1, end, table);
            return std::max(left, right);
        }
        return dfs(ptr + 1, end, table);
    }

    bool check(const std::string &str, int &table)
    {
        for (auto &&c : str)
        {
            int i = c - 'a';
            if (table & (1 << i))
            {
                return false;
            }
            table |= (1 << i);
        }
        return true;
    }
};