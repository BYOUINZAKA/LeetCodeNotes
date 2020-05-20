/*
 * @Author: Hata
 * @Date: 2020-05-20 20:17:08
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-20 20:28:41
 * @FilePath: \LeetCode\442.cpp
 * @Description: https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<int> findDuplicates(std::vector<int> &nums)
    {
        std::vector<int> ans;
        int tmp;
        for (auto &&n : nums)
        {
            tmp = std::abs(n);
            if (nums[tmp - 1] < 0)
                ans.push_back(tmp);
            else
                nums[tmp - 1] = -nums[tmp - 1];
        }
        return ans;
    }
};