/*
 * @Author: Hata
 * @Date: 2020-05-03 22:24:58
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-30 14:19:21
 * @FilePath: \LeetCode\3.cpp
 * @Description: 
 */

#include <bits/stdc++.h>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string &s)
    {
        std::unordered_map<char, std::string::iterator> table;
        int max_sublen = 0;
        for (auto head = s.begin(), tail = s.begin(); tail != s.end(); ++tail)
        {
            auto &&[it, success] = table.try_emplace(*tail, tail);
            if (!success)
            {
                head = std::max(std::next(it->second), head);
            }
            it->second = tail;
            max_sublen = std::max(int(tail - head + 1), max_sublen);
        }
        return max_sublen;
    }
};