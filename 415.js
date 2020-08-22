/*
 * @Author: Hata
 * @Date: 2020-08-03 09:00:41
 * @LastEditors: Hata
 * @LastEditTime: 2020-08-03 09:23:53
 * @FilePath: \LeetCode\415.js
 * @Description: https://leetcode-cn.com/problems/add-strings/
 */

/**
* @param {string} num1
* @param {string} num2
* @return {string}
*/
const addStrings = function(num1, num2) {
    let a = num1.length, b = num2.length, result = '', tmp = 0;
    while(a || b) {
        a ? tmp += +num1[--a] : '';
        b ? tmp +=  +num2[--b] : '';
        
        result = tmp % 10 + result;
        if(tmp > 9) tmp = 1;
        else tmp = 0;
    }
    if (tmp) result = 1 + result;
    return result;
};