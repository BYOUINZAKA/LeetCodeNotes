/*
 * @Author: Hata
 * @Date: 2020-05-19 10:16:44
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-19 10:17:36
 * @FilePath: \LeetCode\204.cpp
 * @Description: https://leetcode-cn.com/problems/count-primes/
 */
#include <bits/stdc++.h>

class Solution
{
private:
    bool isPrime(int x)
    {
        if (x < 2)
            return false;
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
                return false;
        return true;
    }

public:
    int countPrimes(int n)
    {
        int cnt = 0;
        for (int i = 2; i < n; i++)
            if (isPrime(i))
                cnt++;
        return cnt;
    }
};