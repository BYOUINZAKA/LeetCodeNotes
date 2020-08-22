/*
 * @Author: Hata
 * @Date: 2020-08-17 13:19:40
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-17 13:28:36
 * @FilePath: \LeetCode\1004.cpp
 * @Description: https://leetcode-cn.com/problems/max-consecutive-ones-iii/
 */

#include <bits/stdc++.h>

class Solution {
public:
    int longestOnes(std::vector<int>& A, int K) {
        const int N = A.size();

        int l = 0, r = 0;
        int maxLen = 0;
        
        std::deque<int> swindow;

        for (; r < N; ++r) {
            if (A[r] == 0) {
                swindow.push_back(r);
                if (swindow.size() > K) {
                    l = swindow.front() + 1;
                    swindow.pop_front();
                }
            }
            maxLen = std::max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};