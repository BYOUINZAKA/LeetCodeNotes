/*
 * @Author: Hata
 * @Date: 2020-07-27 20:41:13
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-27 21:26:36
 * @FilePath: \LeetCode\47.cpp
 * @Description: https://leetcode-cn.com/problems/permutations-ii/
 */
#include <bits/stdc++.h>

class Solution {
    std::vector<std::vector<int>> res;

public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
        backtracks(nums, std::vector<int>{}, std::vector<int8_t>(nums.size(), false));
        return res;
    }

private:
    template <class List, class Set>
    void backtracks(const std::vector<int> &nums, List &&currList, Set &&visited) {
        const int length = nums.size();

        if (currList.size() == length) {
            res.push_back(currList);
            return;
        }

        std::unordered_set<int> table;
        for (int i = 0; i < length; ++i) {
            if (visited[i] || table.find(nums[i]) != table.end()) continue;

            visited[i] = true;
            currList.push_back(nums[i]);

            table.insert(nums[i]);
            backtracks(nums, std::forward<List>(currList), std::forward<Set>(visited));

            visited[i] = false;
            currList.pop_back();
        }
    }
};

#include "tools.h"

template <class T>
T &ToLValue(T &&v) {
    return std::forward<T &>(v);
}

int main() {
    std::cout << lctools::Formatter::ToString(
                     Solution{}.permuteUnique(ToLValue(std::vector<int>{1, 1, 2, 2, 3})))
              << std::endl;
}