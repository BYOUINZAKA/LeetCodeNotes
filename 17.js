/*
 * @Author: Hata
 * @Date: 2020-07-28 08:58:02
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-28 09:26:00
 * @FilePath: \LeetCode\17.js
 * @Description: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 */

/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function (digits) {
    const length = digits.length;
    if (length === 0) return [];

    const dict = new Map([
        ["2", ["a", "b", "c"]],
        ["3", ["d", "e", "f"]],
        ["4", ["g", "h", "i"]],
        ["5", ["j", "k", "l"]],
        ["6", ["m", "n", "o"]],
        ["7", ["p", "q", "r", "s"]],
        ["8", ["t", "u", "v"]],
        ["9", ["w", "x", "y", "z"]],
    ]);

    const res = [];
    const backtrack = (str, i) => {
        if (i === length) {
            res.push(str.join(""));
            return;
        }
        const tracks = dict.get(digits[i]);
        for (let sub of tracks) {
            str.push(sub);
            backtrack(str, i + 1);
            str.pop();
        }
    };
    backtrack([], 0);
    return res;
};
