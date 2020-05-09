/*
 * @Author: Hata
 * @Date: 2020-05-04 17:35:01
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-04 18:43:36
 * @FilePath: \test\lc373.cpp
 * @Description: 
 */

#include <bits/stdc++.h>

class Solution
{
public:
    using tuple = std::tuple<int, int, std::vector<int>::const_iterator>;
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int> &nums1, std::vector<int> &nums2, int k)
    {
        std::vector<std::vector<int>> result;

        if (nums1.empty() || nums2.empty())
            return result;

        auto comp = [](const tuple &a, const tuple &b) {
            return std::get<0>(a) + std::get<1>(a) > std::get<0>(b) + std::get<1>(b);
        };

        std::priority_queue<tuple, std::vector<tuple>, decltype(comp)> queue(comp);

        for (auto &&i : nums1)
        {
            queue.push(std::make_tuple(i, nums2.front(), nums2.cbegin()));
        }

        while (!queue.empty() && result.size() < k)
        {
            tuple t = queue.top();
            queue.pop();
            result.push_back(std::vector<int>{std::get<0>(t), std::get<1>(t)});
            if (std::get<2>(t) + 1 != nums2.cend())
            {
                auto p = std::get<2>(t) + 1;
                queue.push(std::make_tuple(std::get<0>(t), *p, p));
            }
        }

        return result;
    }
};

