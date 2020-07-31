'''
@Author: Hata
@Date: 2020-07-27 19:03:44
@LastEditors: Hata
@LastEditTime: 2020-07-27 19:10:40
@FilePath: \LeetCode\13.py
@Description: https://leetcode-cn.com/problems/roman-to-integer/
'''


class Solution:
    table = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
    }

    def romanToInt(self, s: str) -> int:
        res = 0
        for i in range(len(s)-1):
            res = res-Solution.table[s[i]] if Solution.table[s[i]
                                                             ] < Solution.table[s[i+1]] else res+Solution.table[s[i]]
        return res+Solution.table[s[-1]]


Solution().romanToInt("III")
