/*
 * @Author: Hata
 * @Date: 2020-08-22 10:22:06
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-22 10:22:18
 * @FilePath: \LeetCode\679.js
 * @Description: https://leetcode-cn.com/problems/24-game/
 */
/**
 * @param {number[]} nums
 * @return {boolean}
 */
const judgePoint24 = function (nums) {
    if (nums.length == 1)
        return Math.abs(nums[0] - 24) < 1e-6;
    for (let i = 0; i < nums.length; i++)
        for (let j = i + 1; j < nums.length; j++) {
            let rest = nums.filter((value, index) => index != i && index != j);
            if (judgePoint24([nums[i] + nums[j], ...rest]) || judgePoint24([nums[i] * nums[j], ...rest]) ||
                judgePoint24([nums[i] - nums[j], ...rest]) || judgePoint24([nums[j] - nums[i], ...rest]) ||
                judgePoint24([nums[i] / nums[j], ...rest]) || judgePoint24([nums[j] / nums[i], ...rest]))
                return true;
        }
    return false;
}