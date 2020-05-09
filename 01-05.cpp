/*
 * @Author: Hata
 * @Date: 2020-05-06 14:04:00
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-06 14:17:31
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
        auto pair = std::mismatch(first.begin(), first.end(), second.begin(), second.end());
        if (pair.first == first.end() || pair.second == second.end())
            return true;
        if (first.length() == second.length())
        {
            pair.first++;
            pair.second++;
        }
        else if (first.length() > second.length())
            pair.first++;
        else
            pair.second++;
        auto pair2 = std::mismatch(pair.first, first.end(), pair.second, second.end());
        if (pair.first == first.end() && pair.second == second.end())
            return true;
        return false;
    }
};