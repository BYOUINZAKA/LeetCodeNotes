/*
 * @Author: Hata
 * @Date: 2020-06-12 23:59:17
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-13 00:13:24
 * @FilePath: \LeetCode\414.cpp
 * @Description: https://leetcode-cn.com/problems/third-maximum-number/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int thirdMax(std::vector<int> &nums)
    {
        if (nums.size() < 3)
        {
            std::sort(nums.begin(), nums.end());
            return nums.back();
        }
        std::priority_queue<int, std::vector<int>, std::greater_equal<int>> queue;
        queue.push(nums[0]);
        queue.push(nums[1]);
        queue.push(nums[2]);
        for (int i = 3; i < nums.size(); ++i)
        {
            queue.push(nums[i]);
            queue.pop();
        }
        return queue.top();
    }
};