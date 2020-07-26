'''
@Author: Hata
@Date: 2020-07-26 03:41:32
@LastEditors: Hata
@LastEditTime: 2020-07-26 04:09:30
@FilePath: \LeetCode\116.py
@Description: https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
'''


class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return root

        node_queue = [root]

        while node_queue:

            curr = None
            for _ in range(len(node_queue)):

                node = node_queue.pop(0)

                if curr is None:
                    curr = node
                else:
                    curr.next = node
                    curr = curr.next

                if curr.left:
                    node_queue.append(curr.left)
                if curr.right:
                    node_queue.append(curr.right)

        return root
