/*
 * @Author: Hata
 * @Date: 2020-08-01 00:01:17
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-01 00:11:16
 * @FilePath: \LeetCode\495.js
 * @Description: https://leetcode-cn.com/problems/teemo-attacking/
 */


/**
 * @param {number[]} timeSeries
 * @param {number} duration
 * @return {number}
 */
const findPoisonedDuration = function (timeSeries, duration) {
    let end = 0;
    let res = 0;
    for (let val of timeSeries) {
        res += val >= end ? duration : val - end + duration;
        end = val + duration;
    }
    return res;
};