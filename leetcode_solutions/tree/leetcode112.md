# [112. 路径总和](https://leetcode-cn.com/problems/path-sum/)

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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        
        // 遇到叶节点返回
        if (root->val == sum && !root->left && !root->right) return true;
        
        // 向左子树确认路径是否存在
        bool left = hasPathSum(root->left, sum - root->val);
        
        // 向右子树确认路径是否存在
        bool right = hasPathSum(root->right, sum - root->val);
        
        return (left || right);
    }
};
```

