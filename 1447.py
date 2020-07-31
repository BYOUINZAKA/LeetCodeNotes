'''
@Author: Hata
@Date: 2020-07-28 09:49:40
@LastEditors: Hata
@LastEditTime: 2020-07-28 10:20:54
@FilePath: \LeetCode\1447.py
@Description: https://leetcode-cn.com/problems/simplified-fractions/
'''

from math import gcd


class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        return [f"{j}/{i}" for i in range(2, n + 1) for j in range(1, i) if gcd(i, j) is 1]
