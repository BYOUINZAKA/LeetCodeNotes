/*
 * @Author: Hata
 * @Date: 2020-07-26 05:05:03
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-26 05:48:30
 * @FilePath: \LeetCode\1422.js
 * @Description: https://leetcode-cn.com/problems/maximum-score-after-splitting-a-string/
 */

/**
 * @param {string} s
 * @return {number}
 */
const maxScore = function (s) {
    const rightArray = Array.from(s).slice(1).map(Number);

    let left = 1 - s[0];
    let right = rightArray.reduce((prev, curr) => prev + curr);

    return Math.max(...rightArray.map(val => {
        const res = left + right;
        left += 1 - val;
        right -= val;
        return res;
    }));
};
