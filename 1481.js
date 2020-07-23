/*
 * @Author: Hata
 * @Date: 2020-07-23 17:12:16
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-23 20:49:22
 * @FilePath: \LeetCode\1481.js
 * @Description: https://leetcode-cn.com/problems/least-number-of-unique-integers-after-k-removals/
 */

/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
const findLeastNumOfUniqueInts = function (arr, k) {
    const table = new Map();
    arr.forEach((val) => {
        table.set(val, table.has(val) ? table.get(val) + 1 : 1);
    });
    const sortedKey = Array.from(table.values()).sort((l, r) => l - r);
    const len = sortedKey.length;
    for (let i = 0, res = len, count = 0; i < len; ++i, --res) {
        count += sortedKey[i];
        if (count >= k) return count === k ? res - 1 : res;
    }
};

console.log(findLeastNumOfUniqueInts(arr = [4, 3, 1, 1, 3, 3, 2], k = 3));