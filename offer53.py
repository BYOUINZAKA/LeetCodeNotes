'''
@Author: Hata
@Date: 2020-07-30 08:57:58
@LastEditors: Hata
@LastEditTime: 2020-07-30 09:23:57
@FilePath: \LeetCode\offer53.py
@Description: https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
'''


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        def binary(l, r, comp):
            while l <= r:
                mid = (l + r) // 2
                if comp(nums[mid], target):
                    l = mid+1
                else:
                    r = mid-1
            return l, r

        right_l, right_r = binary(l, r, lambda a, b: a <= b)
        if right_r >= 0 and nums[right_r] != target:
            return 0

        left = binary(l, right_r, lambda a, b: a < b)

        return right_l - left[1] - 1
