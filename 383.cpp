/*
 * @Author: Hata
 * @Date: 2020-05-17 11:22:47
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-17 11:30:39
 * @FilePath: \LeetCode\383.cpp
 * @Description: https://leetcode-cn.com/problems/ransom-note/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    bool canConstruct(const std::string &ransomNote, const std::string &magazine)
    {
        int table[26] = {0};
        for (auto &&c : magazine)
        {
            ++table[c - 'a'];
        }
        for (auto &&c : ransomNote)
        {
            if (table[c - 'a']-- == 0)
                return false;
        }
        return true;
    }
};