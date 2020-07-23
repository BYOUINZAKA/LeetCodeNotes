/*
 * @Author: Hata
 * @Date: 2020-07-05 17:18:26
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-05 17:53:32
 * @FilePath: \LeetCode\532.cpp
 * @Description: https://leetcode-cn.com/problems/k-diff-pairs-in-an-array/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int findPairs(std::vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;
        std::unordered_set<int> set(nums.begin(), nums.end());
        if (k == 0)
            return nums.size() - set.size();
        std::unordered_set<int> left;
        for (auto &&i : nums)
        {
            if (set.find(i + k) != set.end())
                left.insert(i);
            if (set.find(i - k) != set.end())
                left.insert(i - k);
        }
        return left.size();
    }
};