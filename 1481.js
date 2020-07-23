/*
 * @Author: Hata
 * @Date: 2020-07-23 17:12:16
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-23 17:28:42
 * @FilePath: \LeetCode\1481.js
 * @Description: https://leetcode-cn.com/problems/least-number-of-unique-integers-after-k-removals/
 */

/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var findLeastNumOfUniqueInts = function (arr, k) {
    const table = {};
    arr.forEach((val) => {
        table[val] = table[val] ? table[val] + 1 : 1;
    });
    const sortedKey = Object.keys(table).sort((l, r) => table[l] - table[r]);
    const len = sortedKey.length;
    for (let i = 0, count = 0; i < len; ++i) {
        count += table[sortedKey[i]]
        if (count === k) return len - i - 1;
        if (count > k) return len - i
    }
};

console.log(findLeastNumOfUniqueInts(arr = [4, 3, 1, 1, 3, 3, 2], k = 3));