/*
 * @Author: Hata
 * @Date: 2020-06-04 18:11:34
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-04 18:54:46
 * @FilePath: \LeetCode\5.cpp
 * @Description: https://leetcode-cn.com/problems/longest-palindromic-substring/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::pair<int, int> expandAroundCenter(const std::string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    std::string longestPalindrome(const std::string &s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};