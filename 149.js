/*
 * @Author: Hata
 * @Date: 2020-07-23 18:41:21
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-24 17:54:55
 * @FilePath: \LeetCode\149.js
 * @Description: https://leetcode-cn.com/problems/max-points-on-a-line/
 */

/**
 * @param {number[][]} points
 * @return {number}
 */
maxPoints = function (points) {
    const length = points.length;
    if (length < 3) return length;

    const equal = (p1, p2) => p1[0] === p2[0] && p1[1] === p2[1];
    const gcd = (m, n) => n === 0 ? m : gcd(n, m % n);
    const getSlope = (p1, p2) => {
        const dx = p1[0] - p2[0];
        const dy = p1[1] - p2[1];
        const d = gcd(dy, dx);
        return d === 0 ? [dy, dx] : [dy / d, dx / d];
    };

    let res = 0;
    points.forEach((val, idx) => {
        let same = 1;
        let max = 0;
        const table = new Map();
        for (let j = idx + 1; j < length; ++j) {
            if (equal(val, points[j])) {
                ++same;
            } else {
                const slope = getSlope(points[j], val).toString();
                table.set(slope, table.has(slope) ? table.get(slope) + 1 : 1);
                max = Math.max(max, table.get(slope));
            }
        }
        res = Math.max(res, max + same);
    });
    return res;
};

console.log(maxPoints([[1, 1], [2, 2], [3, 3]]));
console.log(maxPoints([[1, 1], [3, 2], [5, 3], [4, 1], [2, 3], [1, 4]]));
console.log(maxPoints([[0, 0], [1, 1], [0, 0]]));