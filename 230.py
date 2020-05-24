'''
@Author: Hata
@Date: 2020-05-24 15:30:19
@LastEditors: Hata
@LastEditTime: 2020-05-24 15:32:04
@FilePath: \LeetCode\230.py
@Description: https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
'''


class Solution:
    def kthSmallest(self, root, k):
        def gen(r):
            if r is not None:
                yield from gen(r.left)
                yield r.val
                yield from gen(r.right)

        it = gen(root)
        for _ in range(k):
            ans = next(it)
        return ans
