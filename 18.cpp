/*
 * @Author: Hata
 * @Date: 2020-05-10 07:10:52
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-10 08:04:02
 * @FilePath: \LeetCode\18.cpp
 * @Description: https://leetcode-cn.com/problems/4sum/
 */

#include <bits/stdc++.h>

struct Comp
{
    bool operator()(const std::tuple<int, int> &a, const std::tuple<int, int> &b)
    {
        return (std::get<0>(a) + std::get<1>(a)) < (std::get<0>(b) + std::get<1>(b));
    }
};

class Solution
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
    {
        std::vector<std::vector<int>> result;
        std::unordered_map<int, std::set<std::tuple<int, int>, Comp>> map;

        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                map[nums[i] + nums[j]].emplace(nums[i], nums[j]);

        for (auto it = map.begin(); it != map.end(); ++it)
        {
            std::cout << it->first << ' ';
            for (auto &&i : it->second)
                std::cout << std::get<0>(i) << ',' << std::get<1>(i) << ' ';
            std::cout << std::endl;
        }
        return result;
    }
};