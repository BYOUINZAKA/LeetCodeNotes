/*
 * @Author: Hata
 * @Date: 2020-05-11 14:36:26
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-11 15:05:51
 * @FilePath: \LeetCode\560.cpp
 * @Description: https://leetcode-cn.com/problems/subarray-sum-equals-k/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int subarraySum(std::vector<int> &nums, int k)
    {
        int sum = 0, ans = 0;
        std::unordered_map<int, int> map{{0, 1}};
        for (auto &&i : nums)
        {
            sum += i;
            if (map.find(sum - k) != map.end())
                ans += map[sum - k];
            map[sum]++;
        }
        return ans;
    }
};