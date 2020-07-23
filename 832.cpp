/*
 * @Author: Hata
 * @Date: 2020-07-11 12:19:43
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-11 12:23:52
 * @FilePath: \LeetCode\832.cpp
 * @Description: https://leetcode-cn.com/problems/flipping-an-image/
 */
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& A)
    {
        std::for_each(A.begin(), A.end(), [](auto&& row) {
            std::reverse(row.begin(), row.end());
            std::for_each(row.begin(), row.end(), [](auto&& i) {
                i = !i;
            });
        });
        return A;
    }
};