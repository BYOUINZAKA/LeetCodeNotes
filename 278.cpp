/*
 * @Author: Hata
 * @Date: 2020-05-08 13:01:54
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-20 18:53:14
 * @FilePath: \LeetCode\278.cpp
 * @Description: 
 */

#include "leetcode.h"

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 1, h = n;
        int mid;
        while (l < h)
        {
            mid = l + (h - l) / 2.0;
            if (isBadVersion(mid))
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};