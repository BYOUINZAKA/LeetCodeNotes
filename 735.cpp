/*
 * @Author: Hata
 * @Date: 2020-07-21 21:39:19
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-21 23:24:53
 * @FilePath: \LeetCode\735.cpp
 * @Description: https://leetcode-cn.com/problems/asteroid-collision/
 */
#include <bits/stdc++.h>

class Solution {
    enum Status {
        BOTH_KEPT = 0B00,
        RIGHT_BROKEN = 0B01,
        LEFT_BROKEN = 0B10,
        BOTH_BROKEN = RIGHT_BROKEN | LEFT_BROKEN,
    };

public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::deque<int> stack;
        for (auto&& i : asteroids) {
            while (!stack.empty() && collid(stack.back(), i) == LEFT_BROKEN) stack.pop_back();

            auto status = stack.empty() ? BOTH_KEPT : collid(stack.back(), i);
            if (status == BOTH_KEPT)
                stack.push_back(i);
            else if (status == BOTH_BROKEN)
                stack.pop_back();
        }

        return {stack.begin(), stack.end()};
    }

private:
    constexpr Status collid(int left, int right) const {
        if (left > 0 && right < 0) {
            int right_size = -right;
            return left > right_size ? RIGHT_BROKEN
                                     : (left == right_size ? BOTH_BROKEN : LEFT_BROKEN);
        }
        return BOTH_KEPT;
    }
};