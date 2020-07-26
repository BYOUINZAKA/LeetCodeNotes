/*
 * @Author: Hata
 * @Date: 2020-07-26 04:14:21
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-26 05:02:55
 * @FilePath: \LeetCode\881.cpp
 * @Description: https://leetcode-cn.com/problems/boats-to-save-people/
 */

#include <bits/stdc++.h>

#include "tools.h"

class Solution {
public:
    template <class List>
    int numRescueBoats(List&& people, const int limit) {
        std::sort(people.begin(), people.end());
        auto left = people.begin(), right = people.end();

        int res = 0;

        while (left < right) {
            ++res;
            if (*left + *--right <= limit) ++left;
        }

        return res;
    }
};

int main() {
    std::cout << Solution{}.numRescueBoats(std::vector<int>{3, 5, 3, 4}, 5) << std::endl;
    std::cout << Solution{}.numRescueBoats(std::vector<int>{1, 2}, 3) << std::endl;
    std::cout << Solution{}.numRescueBoats(std::deque<int>{3, 2, 2, 1}, 3) << std::endl;
}