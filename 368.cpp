/*
 * @Author: Hata
 * @Date: 2020-06-08 18:42:35
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-11 22:44:52
 * @FilePath: \LeetCode\368.cpp
 * @Description: https://leetcode-cn.com/problems/largest-divisible-subset/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<int> largestDivisibleSubset(std::vector<int> &nums)
    {
        int sz = nums.size(), mx = 0, end = -1;
        std::vector<int> dp(sz, 1), last(sz, -1), res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] <= dp[j])
                {
                    dp[i] = dp[j] + 1;
                    last[i] = j;
                }
            }
            if (dp[i] > mx)
            {
                mx = dp[i];
                end = i;
            }
        }
        for (int i = end; i != -1; i = last[i])
            res.push_back(nums[i]);
        return res;
    }
};

int main()
{
    std::vector<int> list{8, 7, 4, 2};
    auto res = Solution{}.largestDivisibleSubset(list);
    for (auto &&i : res)
        std::cout << i << ", ";
    return 0;
}