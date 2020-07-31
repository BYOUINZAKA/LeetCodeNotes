/*
 * @Author: Hata
 * @Date: 2020-07-27 18:25:36
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-27 18:34:20
 * @FilePath: \LeetCode\392.js
 * @Description: https://leetcode-cn.com/problems/is-subsequence/
 */

/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
const isSubsequence = function (s, t) {
    const n = s.length, m = t.length;
    let i = 0, j = 0;
    for (; i < n && j < m; ++j)
        s[i] === t[j] && ++i;
    return i === n;
};