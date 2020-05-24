/*
 * @Author: Hata
 * @Date: 2020-05-24 13:58:12
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-24 14:07:47
 * @FilePath: \LeetCode\1423.cpp
 * @Description: https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int maxScore(std::vector<int> &cardPoints, int k)
    {
        int sum = std::accumulate(cardPoints.cbegin(), cardPoints.cend(), 0);
        int windowSize = cardPoints.size() - k;
        int windowSum = std::accumulate(cardPoints.cbegin(), cardPoints.cbegin() + windowSize, 0);
        int min = windowSum;
        for (auto it = cardPoints.cbegin() + 1, end = cardPoints.cend() + 1 - windowSize; it != end; ++it)
        {
            windowSum -= *(it - 1);
            windowSum += *(it + windowSize - 1);
            min = std::min(min, windowSum);
        }
        return sum - min;
    }
};