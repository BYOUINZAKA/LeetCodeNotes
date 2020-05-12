/*
 * @Author: Hata
 * @Date: 2020-05-12 10:38:12
 * @LastEditors: Hata
 * @LastEditTime: 2020-05-12 10:47:06
 * @FilePath: \LeetCode\175.sql
 * @Description: https://leetcode-cn.com/problems/combine-two-tables/
 */

SELECT FirstName, LastName, City, State
FROM Person
LEFT JOIN Address ON Person.PersonId = Address.PersonId;