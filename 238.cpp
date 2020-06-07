/*
 * @Author: Hata
 * @Date: 2020-06-04 19:10:02
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-04 19:23:23
 * @FilePath: \LeetCode\238.cpp
 * @Description: https://leetcode-cn.com/problems/product-of-array-except-self/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        std::vector<int> output{1};
        for (auto it = nums.cbegin(); it + 1 != nums.end(); ++it)
        {
            output.push_back(output.back() * *it);
        }
        int ans = 1;
        for (int i = output.size() - 1; i >= 0; --i)
        {
            output[i] *= ans;
            ans *= nums[i];
        }
        return output;
    }
};