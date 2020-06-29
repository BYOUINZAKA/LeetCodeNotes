/*
 * @Author: Hata
 * @Date: 2020-06-22 19:44:50
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-22 19:48:52
 * @FilePath: \LeetCode\275.cpp
 * @Description: https://leetcode-cn.com/problems/h-index-ii/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int hIndex(std::vector<int> &citations)
    {
        int len = citations.size();
        int left = 0, right = len;
        while (left < right)
        {
            int mid = (left + right) / 2.0;
            if (citations[mid] >= len - mid)
                right = mid;
            else
                left = mid + 1;
        }
        return len - right;
    }
};