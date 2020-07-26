/*
 * @Author: Hata
 * @Date: 2020-07-26 02:49:45
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-26 02:50:01
 * @FilePath: \LeetCode\competition\20200725\B.cpp
 * @Description:
 */

#include "leetcode.h"

class Solution {
    const int MOD = 1e9 + 7;

public:
    int numOfSubarrays(vector<int>& arr) {
        const int N = arr.size();
        vector<int64_t> odds(N, 0), evens(N, 0);
        (isOdd(arr[0]) ? odds[0] : evens[0]) = 1;
        for (int i = 1; i < N; ++i) {
            if (isOdd(arr[i])) {
                odds[i] = evens[i - 1] + 1;
                evens[i] = odds[i - 1];
            } else {
                odds[i] = odds[i - 1];
                evens[i] = evens[i - 1] + 1;
            }
        }
        int sum = 0;
        for (auto&& i : odds) {
            sum += i;
            sum %= MOD;
        }
        return sum;
    }

    constexpr bool isOdd(int val) { return val & 0b1; }
};