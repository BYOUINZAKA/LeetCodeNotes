/*
 * @Author: Hata
 * @Date: 2020-07-28 09:32:04
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-28 09:46:10
 * @FilePath: \LeetCode\1291.js
 * @Description: https://leetcode-cn.com/problems/sequential-digits/
 */

/**
* @param {number} low
* @param {number} high
* @return {number[]}
*/
var sequentialDigits = function (low, high) {
    const res = [];
    const backtrack = (val, cur) => {
        if (cur >= 10) return;
        val = val * 10 + cur;
        if (val > high) return;
        if (low <= val && val <= high) res.push(val);
        backtrack(val, cur + 1);
    };
    for (let i = 1; i < 10; ++i) backtrack(0, i);
    return res.sort((a, b) => a - b);
};