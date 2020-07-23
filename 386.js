/*
 * @Author: Hata
 * @Date: 2020-07-23 16:37:53
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-23 17:05:27
 * @FilePath: \LeetCode\386.js
 * @Description: https://leetcode-cn.com/problems/lexicographical-numbers/
 */

/**
 * @param {number} n
 * @return {number[]}
 */
let lexicalOrder = function (n) {
    /**
     * @param {number[]} array
     * @param {number} i
     */
    let dfs = function (array, i) {
        if (i > n) return;
        array.push(i);
        const next = 10 * i;
        for (let j = 0; j < 10; ++j) {
            dfs(array, next + j);
        }
    };
    let res = [];
    for (let i = 1; i < 10; ++i) dfs(res, i);
    return res;
};
console.log(lexicalOrder(13));