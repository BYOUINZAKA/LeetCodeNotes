/*
 * @Author: Hata
 * @Date: 2020-06-07 17:04:25
 * @LastEditors: Hata
 * @LastEditTime: 2020-07-23 16:03:45
 * @FilePath: \LeetCode\513.cs
 * @Description: https://leetcode-cn.com/problems/find-bottom-left-tree-value/
 */

public class Solution
{
    public int FindBottomLeftValue(TreeNode root)
    {
        var queue = new Queue<TreeNode>();
        int res = 0;
        if (root != null)
            queue.Enqueue(root);
        while (queue.Count != 0)
        {
            var size = queue.Count;
            res = queue.Peek().val;
            for (var i = 0; i < size; ++i)
            {
                TreeNode node = queue.Dequeue();
                if (node.left != null)
                    queue.Enqueue(node.left);
                if (node.right != null)
                    queue.Enqueue(node.right);
            }
        }
        return res;
    }

    static void Main()
    {
        System.Console.WriteLine("Hello World!");
    }
}