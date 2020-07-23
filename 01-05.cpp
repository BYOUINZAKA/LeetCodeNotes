/*
 * @Author: Hata
 * @Date: 2020-05-06 14:04:00
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-01 15:26:14
 * @FilePath: \LeetCode\01-05.cpp
 * @Description: 
 */

#include <bits/stdc++.h>

class Solution
{
public:
    bool oneEditAway(const std::string &first, const std::string &second)
    {
        if (std::abs(int(first.length()) - int(second.length())) > 1)
            return false;

        auto &&[it1, it2] = std::mismatch(first.cbegin(), first.cend(), second.cbegin(), second.cend());
        auto &&[rit1, rit2] = std::mismatch(first.crbegin(), first.crend(), second.crbegin(), second.crend());

        return (rit1.base() - it1 <= 1) && (rit2.base() - it2 <= 1);
    }
};