/*
 * @Author: Hata
 * @Date: 2020-07-25 18:03:58
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-25 19:50:30
 * @FilePath: \LeetCode\338.js
 * @Description: https://leetcode-cn.com/problems/counting-bits/
 */

const maxResult = { k: 1, res: [0] };

/**
 * @param {number} num
 * @return {number[]}
 */
const countBits = function (num) {
    const res = maxResult.res;
    for (let i = res.length; i <= num; maxResult.k <<= 1) {
        for (let j = 0; j < maxResult.k; ++j, ++i) {
            res[i] = res[j] + 1;
        }
    }
    return res.slice(0, num + 1);
};

new Array(50)
    .fill()
    .map((val, idx) => idx)
    .sort((a, b) => b - a)
    .forEach(val => console.log(`${val}:\t ${countBits(val).length}, { ${maxResult.k}, ${maxResult.res} };`));