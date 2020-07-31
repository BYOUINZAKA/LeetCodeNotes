/*
 * @Author: Hata
 * @Date: 2020-07-29 17:49:02
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-29 18:51:59
 * @FilePath: \LeetCode\1438.cpp
 * @Description:
 * https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
 */

#include <bits/stdc++.h>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums, int limit) {
        int res = 0;
        std::deque<std::vector<int>::iterator> fall_stack, rise_stack;

        std::less<int> less{};
        std::greater<int> greater{};

        for (auto l = nums.begin(), r = nums.begin(); r != nums.end(); ++r) {
            insert(fall_stack, r, less);
            insert(rise_stack, r, greater);

            while (*fall_stack.front() - *rise_stack.front() > limit) {
                auto&& q = fall_stack.front() < rise_stack.front() ? fall_stack : rise_stack;

                l = q.front() + 1;
                q.pop_front();

                if (q.empty()) break;
            }

            res = std::max(res, int(r - l + 1));
        }

        return res;
    }

private:
    template <class Iter, class Callable>
    void insert(std::deque<Iter>& stack, Iter val, Callable&& func) {
        for (auto&& real = *val; !stack.empty() && func(*stack.back(), real);) stack.pop_back();
        stack.push_back(val);
    }
};