'''
@Author: Hata
@Date: 2020-07-30 08:50:10
@LastEditors: Hata
@LastEditTime: 2020-07-30 08:55:46
@FilePath: \LeetCode\343.py
@Description: https://leetcode-cn.com/problems/integer-break/
'''


class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [0 for _ in range(n+1)]
        for i in range(2, n + 1):
            cur_max = 0
            for j in range(1, i):
                cur_max = max(cur_max, max(j * (i - j), j * dp[i - j]))
            dp[i] = cur_max
        return dp[-1]
