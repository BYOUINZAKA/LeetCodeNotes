'''
Author: Hata
Date: 2020-08-14 12:58:01
LastEditors: Hata
LastEditTime: 2020-08-14 13:02:46
FilePath: \LeetCode\905.py
Description: https://leetcode-cn.com/problems/sort-array-by-parity/
'''

from typing import List


class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        l, r = 0, len(A) - 1
        while l < r:
            sl, sr = A[l] % 2, A[r] % 2
            if sl > sr:
                A[l], A[r] = A[r], A[l]
            if sl == 0:
                l += 1
            if sr == 1:
                r -= 1
        return A
