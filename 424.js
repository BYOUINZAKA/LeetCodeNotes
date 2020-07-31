/*
 * @Author: Hata
 * @Date: 2020-07-27 18:37:33
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-27 19:00:59
 * @FilePath: \LeetCode\424.js
 * @Description: https://leetcode-cn.com/problems/longest-repeating-character-replacement/solution/
 */

/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
const characterReplacement = function (s, k) {
    const alphabet = Array.from({ length: 26 }, () => 0);
    const charList = Array.from(s, val => val.charCodeAt() - 65);
    let maxCount = 0, res = 0;
    let l = 0;
    charList.forEach((val, r) => {
        maxCount = Math.max(maxCount, ++alphabet[val]);
        if (r - l + 1 - maxCount <= k) {
            res = Math.max(res, r - l + 1);
        } else {
            --alphabet[charList[l]];
            ++l;
        }
    });
    return res;
};

console.log(characterReplacement(s = "AABABBA", k = 1));