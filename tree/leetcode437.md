# [437. 路径总和 III](https://leetcode-cn.com/problems/path-sum-iii/)

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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return count(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    
private:
    int count(TreeNode* node, int sum)
    {
        if (!node) return 0;
        return (node->val == sum) + count(node->left, sum - node->val) + count(node->right, sum - node->val);
    }
};
```

- `count(TreeNode*, int)`用于数出自己为开头的路径数
- `(node->val == sum)`用于判断自己本身能否作为一条单独的路径

