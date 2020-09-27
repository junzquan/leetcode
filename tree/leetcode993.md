# [993. 二叉树的堂兄弟节点](https://leetcode-cn.com/problems/cousins-in-binary-tree/)

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root->left, 1, x, y, root->val);
        dfs(root->right, 1, x, y, root->val);
        return (xpar != ypar) && (xdep == ydep);
    }

private:
    void dfs(TreeNode* node, int dep, int x, int y, int par)
    {
        if (!node) return;

        if (node->val == x)
        {
            xpar = par;
            xdep = dep;
        }
        else if (node->val == y)
        {
            ypar = par;
            ydep = dep;
        }
        else
        {
            dfs(node->left, dep + 1, x, y, node->val);
            dfs(node->right, dep + 1, x, y, node->val);
        }
    }

    int xpar, xdep, ypar, ydep;
};
```

- 用 `DFS` 查找 `x` 和 `y` 的深度和父节点的值。

## 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(H)