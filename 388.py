'''
@Author: Hata
@Date: 2020-08-01 19:28:54
@LastEditors: Hata
@LastEditTime: 2020-08-01 19:34:46
@FilePath: \LeetCode\388.py
@Description: https://leetcode-cn.com/problems/longest-absolute-file-path/
'''


class Solution:
    def lengthLongestPath(self, input: str) -> int:
        prefixSum = [0]
        res = 0
        for line in input.split('\n'):
            real = line.lstrip('\t')
            length = len(real)
            depth = len(line) - length
            if '.' in line:
                res = max(res, prefixSum[depth] + length)
            else:
                if depth + 1 < len(prefixSum):
                    prefixSum[depth + 1] = prefixSum[depth] + length + 1
                else:
                    prefixSum.append(prefixSum[-1] + length + 1)
        return res
