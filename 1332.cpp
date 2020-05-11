/*
 * @Author: Hata
 * @Date: 2020-05-11 15:43:31
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-11 15:48:40
 * @FilePath: \LeetCode\1332.cpp
 * @Description: https://leetcode-cn.com/problems/remove-palindromic-subsequences/
 */

#include <bits/stdc++.h>

class Solution
{
public:
    int removePalindromeSub(const std::string &s)
    {
        if (s.empty())
            return 0;
        for (int i = 0; i <= s.length() / 2.0; ++i)
            if (s[i] != s[s.length() - 1 - i])
                return 2;
        return 1;
    }
};