/*
 * @Author: Hata
 * @Date: 2020-08-20 12:08:48
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-20 12:39:34
 * @FilePath: \LeetCode\718.cpp
 * @Description: https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/
 */

#include <bits/stdc++.h>

class Solution {
public:
    int findLength(std::vector<int>& A, std::vector<int>& B) {
        const int N = A.size(), M = B.size();
        int res = 0;

        for (int i = 0; i < N; ++i) {
            int len = std::min(M, N - i);
            res = std::max(res, searchMaxLength(A, B, std::make_pair(i, 0), len));
        }

        for (int i = 0; i < M; ++i) {
            int len = std::min(M - i, N);
            res = std::max(res, searchMaxLength(A, B, std::make_pair(0, i), len));
        }

        return res;
    }

    template <class List, class Pair>
    int searchMaxLength(List&& A, List&& B, Pair&& offsets, int length) {
        auto&& [oa, ob] = offsets;
        
        int res = 0, count = 0;
        
        for (int i = 0; i < length; ++i) {
            if (A[oa + i] == B[ob + i]) {
                count++;
            } else {
                count = 0;
            }
            res = std::max(res, count);
        }
        return res;
    }
};