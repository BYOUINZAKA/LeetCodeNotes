/*
 * @Author: Hata
 * @Date: 2020-07-26 02:48:53
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-26 02:48:53
 * @FilePath: \LeetCode\competition\20200725\A.cpp
 * @Description:
 */

class Solution {
public:
    int countOdds(int low, int high) { return (high - low) / 2 + ((low & 0b1) || (high & 0b1)); }
};