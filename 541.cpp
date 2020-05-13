/*
 * @Author: Hata
 * @Date: 2020-05-13 13:10:59
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-13 13:23:34
 * @FilePath: \LeetCode\541.cpp
 * @Description: https://leetcode-cn.com/problems/reverse-string-ii/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::string reverseStr(std::string &s, int k)
    {
        int kk = 2 * k;
        for (auto begin = s.begin(), end = s.begin() + k;; begin += kk, end += kk)
        {
            if (end <= s.end())
                std::reverse(begin, end);
            else
            {
                std::reverse(begin, s.end());
                break;
            }
        }
        return s;
    }
};