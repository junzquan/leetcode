# [543. 二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/)

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
    int diameterOfBinaryTree(TreeNode* root) {
        int distance = 0;
        dfs(distance, root);
        return distance;
    }

private:
    int dfs(int& distance, TreeNode* node)
    {
        if (!node) return 0;
        int left = dfs(distance, node->left);
        int right = dfs(distance, node->right);
        distance = max(distance, left + right);
        return max(left, right) + 1;
    }
};
```

- 本质上是求树的最大深度，顺带求出树的直径；
- 使用 `dfs` 遍历树，每个节点都更新直径 `distance`。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(N)