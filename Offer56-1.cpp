/*
 * @Author: Hata
 * @Date: 2020-08-22 10:36:16
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-22 10:54:58
 * @FilePath: \LeetCode\Offer56-1.cpp
 * @Description: https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
 */

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> singleNumbers(std::vector<int>& nums) {
        int ret = 0;

        for (auto&& n : nums) ret ^= n;

        int div = 1;
        while ((div & ret) == 0) div <<= 1;

        int a = 0, b = 0;
        for (auto&& n : nums) {
            if (div & n)
                a ^= n;
            else
                b ^= n;
        }

        return {a, b};
    }
};