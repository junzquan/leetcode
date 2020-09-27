# [124. 二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)

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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(res, root);
        return res;
    }

private:
    int dfs(int& res, TreeNode* node)
    {
        if (node == nullptr) return 0;

        int leftSum  = max(dfs(res, node->left), 0);
        int rightSum = max(dfs(res, node->right), 0);

        int sum = node->val + leftSum + rightSum;
        res = max(sum, res);
        return node->val + max(leftSum, rightSum);
    }
};
```

- 对于任意节点 `node`，分别递归求得左右子树的最大路径和，如果左右子树的最大路径和小于 `0` ，则对当前节点无增益，将其设为 `0` ；
- 然后更新结果 `res`， 并返回当前节点的值加上左右子树的最大路径和的较大值。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(log N)