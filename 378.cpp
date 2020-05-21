/*
 * @Author: Hata
 * @Date: 2020-05-21 11:15:16
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-21 11:17:21
 * @FilePath: \LeetCode\378.cpp
 * @Description: https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    int kthSmallest(std::vector<std::vector<int>> &matrix, int k)
    {
        std::priority_queue<int> queue;
        for (auto &&i : matrix)
        {
            for (auto &&j : i)
            {
                queue.push(j);
                if (queue.size() > k)
                    queue.pop();
            }
        }
        return queue.top();
    }
};