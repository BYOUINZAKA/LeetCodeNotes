/*
 * @Author: Hata
 * @Date: 2020-08-14 12:38:23
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-14 12:46:43
 * @FilePath: \LeetCode\20.js
 * @Description: https://leetcode-cn.com/problems/valid-parentheses/
 */

/**
 * @param {string} s
 * @return {boolean}
 */
const isValid = function (s) {
    const stack = [];
    for (const ch of s) {
        if (ch === '(') stack.push(')');
        else if (ch === '[') stack.push(']');
        else if (ch === '{') stack.push('}');
        else if (stack.length === 0 || stack.pop() !== ch) return false;
    }
    return stack.length === 0;
};