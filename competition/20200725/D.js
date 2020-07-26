/*
 * @Author: Hata
 * @Date: 2020-07-25 23:32:49
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-26 02:49:16
 * @FilePath: \LeetCode\competition\20200725\D.js
 * @Description: 
 */

/**
 * @param {number[]} target
 * @return {number}
 */
var minNumberOperations = function (target) {
    const length = target.length;
    let res = target[0];
    for(let i = 1; i < length; ++i) {
        res += Math.max(0, target[i] - target[i - 1]);
    }
    return res;
};