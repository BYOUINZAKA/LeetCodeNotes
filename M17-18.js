/*
 * @Author: Hata
 * @Date: 2020-07-25 02:39:17
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-25 16:28:47
 * @FilePath: \LeetCode\M17-18.js
 * @Description: https://leetcode-cn.com/problems/shortest-supersequence-lcci/
 */

/**
* @param {number[]} big
* @param {number[]} small
* @return {number[]}
*/
const shortestSeq = function (big, small) {
    const checkTable = new Set();
    const slideTable = new Map();
    small.forEach(val => checkTable.add(val));

    const baseWindowSize = checkTable.size;
    const length = big.length;

    let minLength = Number.MAX_VALUE;
    let res = [];

    for (let l = 0, r = 0; r < length; ++r) {
        const rvalue = big[r];
        if (!checkTable.has(rvalue)) continue;

        slideTable.set(rvalue, slideTable.has(rvalue) ? slideTable.get(rvalue) + 1 : 1);

        for (; slideTable.size == baseWindowSize; ++l) {
            const lvalue = big[l];
            if (!checkTable.has(lvalue)) continue;

            const count = slideTable.get(lvalue) - 1;
            
            count ? slideTable.set(lvalue, count) : slideTable.delete(lvalue);

            count || (r - l < minLength && (() => {
                minLength = r - l;
                res = [l, r];
            })());
        }
    }

    return res;
};