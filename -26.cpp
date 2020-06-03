/*
 * @Author: Hata
 * @Date: 2020-06-02 17:15:05
 * @LastEditors: Hata
 * @LastEditTime: 2020-06-02 17:31:48
 * @FilePath: \LeetCode\-26.cpp
 * @Description: https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
 */
#include "leetcode.h"

class Solution
{
    std::function<bool(TreeNode *, TreeNode *)> dfs;

public:
    Solution()
        : dfs(
              [this](TreeNode *A, TreeNode *B) -> bool {
                  if (B == nullptr)
                      return true;
                  if (A == nullptr)
                      return false;
                  return dfs(A->left, B->left) && dfs(A->right, B->right) && A->val == B->val;
              })
    {
    }

    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (B == nullptr)
            return A == B;
        if (A == nullptr)
            return false;
        return this->dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};