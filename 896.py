'''
@Author: Hata
@Date: 2020-07-25 15:08:20
@LastEditors: Hata
@LastEditTime: 2020-07-25 15:27:56
@FilePath: \LeetCode\896.py
@Description: https://leetcode-cn.com/problems/monotonic-array/
'''


class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        diff = len(A) - 1
        for i in range(len(A)):
            if A[i] is not A[0]:
                diff = i
                break

        list_type = A[0] <= A[diff]

        for i in range(diff+1, len(A)):
            if A[i-1] > A[i] if list_type else A[i-1] < A[i]:
                return False
        return True
