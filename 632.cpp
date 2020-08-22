/*
 * @Author: Hata
 * @Date: 2020-08-01 18:31:28
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-01 18:43:07
 * @FilePath: \LeetCode\632.cpp
 * @Description: https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists/
 */

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
        const int N = nums.size();
        std::unordered_map<int, std::vector<int>> indices;

        int min_value = std::numeric_limits<int>::max(),
            max_value = std::numeric_limits<int>::min();

        for (int i = 0; i < N; ++i) {
            for (auto&& j : nums[i]) {
                indices[j].push_back(i);
                min_value = std::min(j, min_value);
                max_value = std::max(j, max_value);
            }
        }

        std::vector<int> freq(N);
        int inside = 0;
        int left = min_value, right = min_value - 1;
        int bestLeft = min_value, bestRight = max_value;

        while (right < max_value) {
            ++right;
            if (indices.count(right)) {
                for (const int& x : indices[right]) {
                    ++freq[x];
                    if (freq[x] == 1) {
                        ++inside;
                    }
                }
                while (inside == N) {
                    if (right - left < bestRight - bestLeft) {
                        bestLeft = left;
                        bestRight = right;
                    }
                    if (indices.count(left)) {
                        for (const int& x : indices[left]) {
                            --freq[x];
                            if (freq[x] == 0) {
                                --inside;
                            }
                        }
                    }
                    ++left;
                }
            }
        }

        return {bestLeft, bestRight};
    }
};