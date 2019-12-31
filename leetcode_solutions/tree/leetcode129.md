# [129. 求根到叶子节点数字之和](https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/)

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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int sum)
    {
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr)
            return sum + node->val;
        sum += node->val;
        return dfs(node->left, sum * 10) + dfs(node->right, sum * 10);
    }
};
```

- 自顶向下，对任意非叶子节点，让 `sum ` 加上当前节点的值 `node->val` ，然后递归搜索左子树和右子树并返回它们的和；
- 对任意叶子结点，直接返回 `sum + node->val` 。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(log N)