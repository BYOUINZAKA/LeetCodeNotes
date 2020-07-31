/*
 * @Author: Hata
 * @Date: 2020-07-28 00:13:32
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-28 00:16:46
 * @FilePath: \LeetCode\104.js
 * @Description: https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
 */


class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function (root) {
    const dfs = node => node ? 1 + Math.max(dfs(node.left), dfs(node.right)) : 0;
    return dfs(root);
};