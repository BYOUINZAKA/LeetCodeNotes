/*
 * @Author: Hata
 * @Date: 2020-07-27 19:16:16
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-27 19:29:15
 * @FilePath: \LeetCode\515.js
 * @Description: https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/
 */


/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var largestValues = function (root) {
    const res = [];
    if (root === null) return res;

    let queue = [root];

    while (queue.length) {
        res.push(Math.max(...queue.map(node => node.val)));
        queue = queue.flatMap(node => [node.left, node.right]).filter(node => node);
    }
    return res;
};