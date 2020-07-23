/*
 * @Author: Hata
 * @Date: 2020-07-22 17:37:52
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-22 20:17:54
 * @FilePath: \LeetCode\907.cpp
 * @Description: https://leetcode-cn.com/problems/sum-of-subarray-minimums/
 */

#include <bits/stdc++.h>
#include "tools.h"

class Solution {
    const int k_mod = 1e9 + 7;

public:
    int sumSubarrayMins(std::vector<int>& A) {
        const int k_N = A.size();
        std::vector<int> prev(k_N), next(k_N);
        {
            std::stack<int> stack;
            for (int i = 0; i < k_N; ++i) {
                while (!stack.empty() && A[i] <= A[stack.top()]) stack.pop();
                prev[i] = stack.empty() ? -1 : stack.top();
                stack.push(i);
            }
        };
        {
            std::stack<int> stack;
            for (int i = k_N - 1; i >= 0; --i) {
                while (!stack.empty() && A[i] < A[stack.top()]) stack.pop();
                next[i] = stack.empty() ? k_N : stack.top();
                stack.push(i);
            }
        };
        std::cout << lctools::Formatter::ToStringLines(prev, next);
        int ans = 0;    
        for (int i = 0; i < k_N; ++i) {
            ans += (i - prev[i]) * (next[i] - i) % k_mod * A[i] % k_mod;
            ans %= k_mod;
        }
        return ans;
    }
};