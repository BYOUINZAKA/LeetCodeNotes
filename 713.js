/*
 * @Author: Hata
 * @Date: 2020-07-29 20:44:07
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-29 20:46:51
 * @FilePath: \LeetCode\713.js
 * @Description: https://leetcode-cn.com/problems/subarray-product-less-than-k/
 */

/**
* @param {number[]} nums
* @param {number} k
* @return {number}
*/
var numSubarrayProductLessThanK = function (nums, k) {
    if (k <= 1) return 0;

    const n = nums.length;

    let product = 1;
    let res = 0;

    for (let l = 0, r = 0; r < n; ++r) {
        product *= nums[r];
        while (product >= k) product /= nums[l++];
        res += r - l + 1;
    }

    return res;
};