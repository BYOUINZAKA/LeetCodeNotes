/*
 * @Author: Hata
 * @Date: 2020-07-15 16:25:12
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-15 16:32:14
 * @FilePath: \LeetCode\520.cpp
 * @Description: https://leetcode-cn.com/problems/detect-capital/
 */
#include <bits/stdc++.h>

class Solution {
public:
    bool detectCapitalUse(std::string &word) {
        return std::all_of(word.begin(), word.end(), [](auto&& c) { return std::isupper(c); }) ||
               std::all_of(word.begin() + 1, word.end(), [](auto&& c) { return std::islower(c); });
    }
};