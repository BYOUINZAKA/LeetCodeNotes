/*
 * @Author: Hata
 * @Date: 2020-07-23 16:17:28
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-23 18:35:08
 * @FilePath: \LeetCode\1375.js
 * @Description: https://leetcode-cn.com/problems/bulb-switcher-iii/
 */

/**
 * @param {number[]} light
 * @return {number}
 */
const numTimesAllBlue = function (light) {
    return function (max, i) {
        if (i >= light.length) return 0;
        const curMax = Math.max(max, light[i]);
        const nextCount = arguments.callee(curMax, i + 1);
        return curMax === i + 1 ? nextCount + 1 : nextCount;
    }(0, 0);
};

console.log(numTimesAllBlue([2, 1, 4, 3, 6, 5]));
console.log(numTimesAllBlue([2, 1, 3, 5, 4]));