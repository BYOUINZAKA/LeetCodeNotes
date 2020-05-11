/*
 * @Author: Hata
 * @Date: 2020-05-11 16:34:57
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-11 16:40:14
 * @FilePath: \LeetCode\453.cpp
 * @Description: https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/
 */

#include <bits/stdc++.h>


class Solution
{
public:
    int minMoves(std::vector<int> &nums)
    {
        auto min = std::min_element(nums.cbegin(), nums.cend());
        int count = 0;
        for (auto &&i : nums)
            count += i - *min;
        return count;
    }
};