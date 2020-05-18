/*
 * @Author: Hata
 * @Date: 2020-05-17 11:41:03
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-17 13:29:18
 * @FilePath: \LeetCode\395.cpp
 * @Description: https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    using CIter = std::string::const_iterator;
    int longestSubstring(std::string &s, int k)
    {
        return solve(s.cbegin(), s.cend(), k);
    }

    int solve(CIter left, CIter right, int k)
    {
        int res = 0;
        int table[26] = {0};
        std::vector<CIter> splits;

        for (auto it = left; it != right; ++it)
            ++table[*it - 'a'];

        for (auto it = left; it != right; ++it)
            if (table[*it - 'a'] < k)
                splits.push_back(it);
        if (splits.size() == 0)
            return right - left;

        splits.push_back(right);

        for (auto &&it : splits)
        {
            if (right - left > res)
                res = std::max(res, solve(left, it, k));
            left = it + 1;
        }

        return res;
    }
};