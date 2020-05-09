/*
 * @Author: Hata
 * @Date: 2020-05-09 10:00:04
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-09 11:17:50
 * @FilePath: \LeetCode\223.cpp
 * @Description: 
 */

#include "leetcode.h"

class Solution
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        auto x = getX(A, C, E, G);
        auto y = getY(B, D, F, H);
        long long s = getSize(A, B, C, D) + getSize(E, F, G, H);
        return s - getSize(std::get<0>(x), std::get<0>(y), std::get<1>(x), std::get<1>(y));
    }

    std::tuple<int, int> getX(int A, int C, int E, int G)
    {
        if (C <= E || A >= G)
            return std::tuple<int, int>{0, 0};
        else
            return std::tuple<int, int>{std::max(A, E), std::min(C, G)};
    }

    std::tuple<int, int> getY(int B, int D, int F, int H)
    {
        if (D <= F || B >= H)
            return std::tuple<int, int>{0, 0};
        else
            return std::tuple<int, int>{std::max(B, F), std::min(D, H)};
    }

    int getSize(int A, int B, int C, int D)
    {
        return (D - B) * (C - A);
    }
};