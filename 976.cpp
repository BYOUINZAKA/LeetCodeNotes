/*
 * @Author: Hata
 * @Date: 2020-07-21 20:58:37
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-21 21:13:00
 * @FilePath: \LeetCode\976.cpp
 * @Description: https://leetcode-cn.com/problems/largest-perimeter-triangle/
 */
#include <bits/stdc++.h>

class Solution {
public:
    int largestPerimeter(std::vector<int>& A) {
        std::sort(A.begin(), A.end(), std::greater<int>{});
        const int k_size = A.size();
        for (int i = 2; i < k_size; ++i) {
            if (A[i - 2] < A[i - 1] + A[i]) return A[i - 2] + A[i - 1] + A[i];
        }
        return 0;
    }
};