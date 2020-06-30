/*
 * @Author: Hata
 * @Date: 2020-06-30 13:54:26
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-30 14:15:40
 * @FilePath: \LeetCode\offer48.cpp
 * @Description: https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
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