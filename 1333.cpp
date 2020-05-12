/*
 * @Author: Hata
 * @Date: 2020-05-12 09:03:53
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-12 09:21:26
 * @FilePath: \LeetCode\1333.cpp
 * @Description: https://leetcode-cn.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<int> filterRestaurants(std::vector<std::vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance)
    {
        std::sort(restaurants.begin(), restaurants.end(), [](const auto &a, const auto &b) -> bool {
            return a[1] == b[1] ? a[0] > b[0] : a[1] > b[1];
        });
        std::vector<int> result;
        std::for_each(restaurants.begin(), restaurants.end(), [&](const auto &r) {
            if (r[3] <= maxPrice && r[4] <= maxDistance && (veganFriendly == 0 || r[2] == veganFriendly))
                result.push_back(r[0]);
        });
        return result;
    }
};