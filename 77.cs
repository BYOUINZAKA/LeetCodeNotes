/*
 * @Author: Hata
 * @Date: 2020-07-28 12:14:56
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-28 12:44:17
 * @FilePath: \LeetCode\77.cs
 * @Description: https://leetcode-cn.com/problems/combinations/
 */

using System.Collections;

public class Solution
{
    public IList<IList<int>> Combine(int n, int k)
    {
        var results = new List<IList<int>>();
        if (n < 1 || k < 1) return results;

        var route = new List<int>();
        BuildNumberList(1, n, k, ref route, ref results);

        return results;
    }

    private static void BuildNumberList(int start, int end, int length, ref List<int> route, ref List<IList<int>> results)
    {
        if (route.Count == length)
        {
            results.Add(new List<int>(route));
            return;
        }

        for (int index = start; index <= end; ++index)
        {
            route.Add(index);
            BuildNumberList(index + 1, end, length, ref route, ref results);
            route.RemoveAt(route.Count - 1);
        }
    }
}