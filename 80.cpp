/*
 * @Author: Hata
 * @Date: 2020-05-14 08:18:11
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-14 09:12:22
 * @FilePath: \LeetCode\80.cpp
 * @Description: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    constexpr const static int COUNT = 2;
    int removeDuplicates(std::vector<int> &nums)
    {
        for (auto it = nums.begin(); it != nums.end();)
        {
            auto right = std::find_if_not(it + 1, nums.end(), [&it](const auto &v) -> bool { return v == *it; });
            it = right - it > COUNT ? nums.erase(it + COUNT, right) : right;
        }
        return nums.size();
    }
};