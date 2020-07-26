/*
 * @Author: Hata
 * @Date: 2020-07-24 16:12:50
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-24 17:48:37
 * @FilePath: \LeetCode\174.js
 * @Description: https://leetcode-cn.com/problems/dungeon-game/
 */

import * as m149 from "/149.js"

/**
* @param {number[][]} dungeon
* @return {number}
*/
var calculateMinimumHP = dungeon => {
    const kMinHP = 1;
    const kN = dungeon.length;
    const kM = dungeon[0].length;
    console.log(m149.maxPoints([[1, 1], [2, 2], [3, 3]]));

    const dp = new Array(kN + 1);
    for (let i = 0; i <= kN; ++i) { dp[i] = new Array(kM + 1).fill(Number.MAX_VALUE); }

    dp[kN][kM - 1] = dp[kN - 1][kM] = kMinHP;

    for (let i = kN - 1; i >= 0; --i) {
        for (let j = kM - 1; j >= 0; --j) {
            const minValue = Math.min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = Math.max(minValue - dungeon[i][j], kMinHP);
        }
    }
    return dp[0][0];
};

console.log(calculateMinimumHP([[-2, -3, 3], [-5, -10, 1], [10, 30, -5]]));