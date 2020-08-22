/*
 * @Author: Hata
 * @Date: 2020-08-13 12:23:43
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-13 12:34:08
 * @FilePath: \LeetCode\11.js
 * @Description: https://leetcode-cn.com/problems/container-with-most-water/
 */

/**
 * @param {number[]} height
 * @return {number}
 */
const maxArea = function (height) {
    let maxArea = 0;
    let l = 0, r = height.length - 1;
    while (l < r) {
        maxArea = Math.max(maxArea, Math.min(height[l], height[r]) * (r - l));
        height[l] > height[r] ? --r : ++l;
    }
    return maxArea;
};