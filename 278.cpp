/*
 * @Author: Hata
 * @Date: 2020-05-08 13:01:54
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-08 13:44:42
 * @FilePath: \LeetCode\278.cpp
 * @Description: 
 */

#include "leetcode.h"

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 1, h = n;
        int mid;
        do
        {
            mid = l + (h - l) / 2.0;
            if (isBadVersion(mid))
                h = mid - 1;
            else
                l = mid + 1;
        } while (l < h);
        return mid;
    }
};