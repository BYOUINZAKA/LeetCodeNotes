/*
 * @Author: Hata
 * @Date: 2020-05-18 20:43:39
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-18 20:50:57
 * @FilePath: \LeetCode\989.cpp
 * @Description: https://leetcode-cn.com/problems/add-to-array-form-of-integer/
 */
#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<int> addToArrayForm(std::vector<int> &A, int K)
    {
        std::reverse(A.begin(), A.end());
        int index = 0;
        while (K > 0)
        {
            if (index < A.size())
            {
                K += A[index];
                A[index] = K % 10; // 未越界, 直接赋值
            }
            else
            {
                A.push_back(K % 10); // 越界了, push
            }

            K /= 10;
            ++index;
        }
        std::reverse(A.begin(), A.end());
        return A;
    }
};