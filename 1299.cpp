/*
 * @Author: Hata
 * @Date: 2020-05-12 11:27:25
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-12 11:39:35
 * @FilePath: \LeetCode\1299.cpp
 * @Description: https://leetcode-cn.com/problems/replace-elements-with-greatest-element-on-right-side/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<int> replaceElements(std::vector<int> &arr)
    {
        int max = -1;
        std::for_each(arr.rbegin(), arr.rend(), [&max](auto &i, int r = 0) {
            r = i;
            i = max;
            max = std::max(max, r);
        });
        return arr;
    }
};