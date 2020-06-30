/*
 * @Author: Hata
 * @Date: 2020-06-30 15:27:39
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-30 15:35:54
 * @FilePath: \LeetCode\1013.cpp
 * @Description: https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    bool canThreePartsEqualSum(std::vector<int> &A)
    {
        int sum = std::accumulate(A.cbegin(), A.cend(), 0);
        int s = 0, count = 0;
        if (s % 3 != 0)
            return false;
        for (int i = 0; i < A.size(); i++)
        {
            s = s + A[i];
            if (s == sum / 3)
            {
                s = 0;
                count++;
                if (count == 2 && i != A.size() - 1)
                    return true;
            }
        }
        return false;
    }
};