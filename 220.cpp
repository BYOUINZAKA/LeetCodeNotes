/*
 * @Author: Hata
 * @Date: 2020-07-08 10:50:49
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-08 11:33:23
 * @FilePath: \LeetCode\220.cpp
 * @Description: https://leetcode-cn.com/problems/contains-duplicate-iii/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int k, int t)
    {
        std::set<int64_t> tree;
        for (auto it = nums.cbegin(); it != nums.cend(); ++it)
        {
            auto s = tree.lower_bound(int64_t(*it) - t);
            if (s != tree.end() && *s <= int64_t(*it) + t)
                return true;
            tree.insert(int64_t(*it));
            if (tree.size() > k)
                tree.erase(*(it - k));
        }
        return false;
    }
};