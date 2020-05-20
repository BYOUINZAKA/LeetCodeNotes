/*
 * @Author: Hata
 * @Date: 2020-05-20 19:35:53
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-20 19:54:03
 * @FilePath: \LeetCode\187.cpp
 * @Description: https://leetcode-cn.com/problems/repeated-dna-sequences/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    static constexpr const int STEP = 10;
    std::vector<std::string> findRepeatedDnaSequences(const std::string &s)
    {
        std::unordered_map<std::string, int> table;
        std::vector<std::string> res;
        int size = s.size();

        for (int i = 0; i < size - STEP + 1; ++i)
            ++table[s.substr(i, STEP)];

        std::for_each(
            table.begin(),
            table.end(),
            [&res](const auto &p) {
                if (p.second > 1)
                    res.push_back(p.first);
            });

        return res;
    }
};