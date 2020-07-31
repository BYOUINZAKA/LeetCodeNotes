'''
@Author: Hata
@Date: 2020-07-28 00:37:01
@LastEditors: Hata
@LastEditTime: 2020-07-28 00:42:50
@FilePath: \LeetCode\852.py
@Description: https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/
'''


class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        left, right = 0, len(A) - 1
        while left < right:
            mid = (right + left) // 2
            if A[mid] < A[mid+1]:
                left = mid + 1
            else:
                right = mid
        return left
