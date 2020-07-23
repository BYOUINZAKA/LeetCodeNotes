/*
 * @Author: Hata
 * @Date: 2020-07-09 14:10:18
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-09 21:59:58
 * @FilePath: \LeetCode\1219.cpp
 * @Description: https://leetcode-cn.com/problems/path-with-maximum-gold/
 */
#include <bits/stdc++.h>

class Solution
{
    constexpr static const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int max_gold = 0;
    int n, m;

public:
    template <class M,
              typename T = typename std::remove_reference_t<M>::value_type::value_type,
              typename std::enable_if_t<std::is_integral_v<T>, int> = 0>
    int getMaximumGold(M &&grid)
    {
        n = grid.size();
        m = grid.front().size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] != 0)
                    dfs(std::forward<M>(grid), std::vector<int8_t>(n * m, false), i, j, 0);
            }
        }
        return max_gold;
    }

private:
    template <class M,
              class V,
              typename T = typename std::remove_reference_t<V>::value_type,
              typename std::enable_if_t<std::is_integral_v<T>, int> = 0>
    void dfs(M &&grid, V &&visited, int i, int j, int gold)
    {
        visited[i * m + j] = true;
        gold += grid[i][j];

        for (auto &&d : dir)
        {
            int next_i = i + d[0], next_j = j + d[1];
            if (enable(std::forward<M>(grid), std::forward<V>(visited), next_i, next_j))
                dfs(std::forward<M>(grid), std::forward<V>(visited), next_i, next_j, gold);
        }

        max_gold = std::max(max_gold, gold);
        visited[i * m + j] = false;
    }

    template <class M, class V>
    constexpr bool enable(M &&grid, V &&visited, int i, int j) const
    {
        return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != 0 && visited[i * m + j] == false;
    }
};

[[Solution]]
int foo()
{
    std::cout << sizeof(bool) << std::endl;
}

int main()
{
    foo();
    std::cout << sizeof(int8_t) << std::endl;

    std::cout << Solution{}.getMaximumGold(
        std::vector<std::array<int, 6>>{{1, 0, 7, 0, 0, 0}, {2, 0, 6, 0, 1, 0}, {3, 5, 6, 7, 4, 2}, {4, 3, 1, 0, 2, 0}, {3, 0, 5, 0, 20, 0}});

    std::cout << std::endl;

    std::vector<std::vector<int>> param{{1, 0, 7, 0, 0, 0}, {2, 0, 6, 0, 1, 0}, {3, 5, 6, 7, 4, 2}, {4, 3, 1, 0, 2, 0}, {3, 0, 5, 0, 20, 0}};
    std::cout << Solution().getMaximumGold(param) << std::endl;
}