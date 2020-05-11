/*
 * @Author: Hata
 * @Date: 2020-05-11 19:11:15
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-11 19:16:41
 * @FilePath: \LeetCode\169.cpp
 * @Description: https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
 */

#include <bits/stdc++.h>

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        std::unordered_map<int, int> map;
        int check = nums.size() / 2;
        for (auto &&i : nums)
        {
            ++map[i];
            if (map[i] >= check)
                return i;
        }
    }
};