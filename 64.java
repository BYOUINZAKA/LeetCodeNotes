import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/*
 * @Author: Hata
 * @Date: 2020-07-24 04:13:58
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-29 07:04:15
 * @FilePath: \LeetCode\64.java
 * @Description: https://leetcode-cn.com/problems/minimum-path-sum/
 */
class Solution {
    public int minPathSum(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        var dp = new int[n][m];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
            for (int j = 1; j < m; ++j) {
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1][m - 1];
    }

    public Integer value = 7;

    public Integer get() {
        return value;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        Integer ppp = s.value;
        System.out.println(System.identityHashCode(s.value));
        System.out.println(System.identityHashCode(ppp));
        ppp = 5;
        System.out.println(System.identityHashCode(s.value));
        System.out.println(System.identityHashCode(ppp));
    }
}