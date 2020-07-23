/*
 * @Author: Hata
 * @Date: 2020-07-23 16:17:28
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-23 16:34:24
 * @FilePath: \LeetCode\1375.js
 * @Description: https://leetcode-cn.com/problems/bulb-switcher-iii/
 */

/**
 * @param {number[]} light
 * @return {number}
 */
let numTimesAllBlue = function (light) {
    let res = 0, farthest = 0;
    for (let i = 0; i < light.length; ++i) {
        farthest = Math.max(farthest, light[i]);
        if (farthest == i + 1) {
            ++res;
        }
    }
    return res;
};

console.log(numTimesAllBlue([2, 1, 4, 3, 6, 5]));