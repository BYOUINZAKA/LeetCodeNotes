/*
 * @Author: Hata
 * @Date: 2020-05-24 14:10:40
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-24 14:17:52
 * @FilePath: \LeetCode\744.cpp
 * @Description: https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    char nextGreatestLetter(std::vector<char> &letters, char target)
    {
        auto v = std::upper_bound(letters.begin(), letters.end(), target);
        if (v != letters.end())
            return *v;
        else
            return *letters.begin();
    }
};