/*
 * @Author: Hata
 * @Date: 2020-05-06 11:43:56
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-06 11:45:12
 * @FilePath: \LeetCode\1414.cpp
 * @Description: 和为 K 的最少斐波那契数字数目
 */

#include <bits/stdc++.h>
template <int N>
struct Fibo
{
    constexpr static int value = Fibo<N - 1>::value + Fibo<N - 2>::value;
};

template <>
struct Fibo<1>
{
    constexpr static int value = 1;
};

template <>
struct Fibo<0>
{
    constexpr static int value = 1;
};

const constexpr int SIZE = 45;
int FiboList[SIZE];

template <int Index = SIZE - 1>
constexpr void fill()
{
    ::FiboList[Index] = Fibo<Index>::value;
    fill<Index - 1>();
}

template <>
void fill<0>()
{
    ::FiboList[0] = Fibo<0>::value;
}

class Solution
{
public:
    int findMinFibonacciNumbers(int k)
    {
        ::fill();
        int res = 0;
        for (int i = ::SIZE - 1; i >= 0; --i)
        {
            if (k >= ::FiboList[i])
            {
                ++res;
                k -= ::FiboList[i];
            }
        }
        return res;
    }
};