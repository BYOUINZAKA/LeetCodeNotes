/*
 * @Author: Hata
 * @Date: 2020-07-26 17:17:05
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-26 18:52:09
 * @FilePath: \LeetCode\329.js
 * @Description: https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
 */

/**
 * @param {number[][]} matrix
 * @return {number}
 */
var longestIncreasingPath = function (matrix) {
    const n = matrix.length;
    const m = matrix[0] ? matrix[0].length : 0;
    if (n === 0 || n === 0) return 0;

    const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    const dp = Array.from({ length: n }, () => new Array(m));

    const enable = (i, j, d) => {
        const di = i + d[0], dj = j + d[1];
        return di >= 0 && di < n && dj >= 0 && dj < m && matrix[di][dj] > matrix[i][j];
    };

    const dfs = (i, j) => dp[i][j] = dp[i][j] || 1 + Math.max(...dirs.map(d => enable(i, j, d) && dfs(i + d[0], j + d[1])));

    return Math.max(...matrix.map((row, i) => Math.max(...row.map((val, j) => dfs(i, j)))));
};

console.log(longestIncreasingPath([
    [9, 9, 4],
    [6, 6, 8],
    [2, 1, 1]
]));