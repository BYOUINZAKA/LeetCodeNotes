/*
 * @Author: Hata
 * @Date: 2020-07-21 14:58:34
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-21 17:38:50
 * @FilePath: \LeetCode\491.cpp
 * @Description: https://leetcode-cn.com/problems/increasing-subsequences/
 */
#include <bits/stdc++.h>

class Solution {
public:
    template <class List, typename T = typename std::remove_reference_t<List>::value_type>
    std::vector<std::vector<T>> findSubsequences(List &&nums) {
        std::vector<std::vector<T>> res;
        backTrack(res, std::vector<T>{}, nums.begin(), nums.end());
        return res;
    }

private:
    template <class List, typename Iter,
              typename T = typename std::remove_reference_t<List>::value_type>
    void backTrack(std::vector<List> &result, List &&selected, Iter it, Iter end) {
        if (selected.size() >= 2) result.push_back(selected);
        std::unordered_set<T> table;
        for (; it != end; ++it) {
            if (selected.empty() || (*it >= selected.back() && table.find(*it) == table.end())) {
                selected.push_back(*it);
                table.insert(*it);
                backTrack(result, std::forward<List>(selected), std::next(it), end);
                selected.pop_back();
            }
        }
    }
};

#include "tools.h"

int main() {
    std::cout << lctools::Formatter::ToString(
                     Solution{}.findSubsequences(std::vector<float>{4, 6, 7, 7}))
              << std::endl;
    std::cout << lctools::Formatter::ToString(
                     Solution{}.findSubsequences(std::vector<int>{5, 4, 24, 6, 7, 7}))
              << std::endl;
    std::cout << lctools::Formatter::ToString(Solution{}.findSubsequences(
                     std::list<int>{42, 2, 13, 79, 632, 32, 1, 44, 7, 34}))
              << std::endl;
    std::cout << lctools::Formatter::ToString(Solution{}.findSubsequences(
                     std::deque<int>{42, 2, 13, 79, 632, 32, 1, 44, 7, 89345, 34}))
              << std::endl;
    std::cout << lctools::Formatter::ToString(Solution{}.findSubsequences(
                     std::vector<std::string>{"5", "4", "24", "6", "61", "7", "7"}))
              << std::endl;
}