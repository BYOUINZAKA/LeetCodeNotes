/*
 * @Author: Hata
 * @Date: 2020-06-07 17:16:32
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-07 17:22:08
 * @FilePath: \LeetCode\1.cpp
 * @Description: https://leetcode-cn.com/problems/two-sum/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); ++i)
        {
            int temp = target - nums[i];
            if (table.find(temp) != table.end())
            {
                return {i, table[temp]};
            }
            table[nums[i]] = i;
        }
        return {-1, -1};
    }
};