# [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

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
    int maxDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        else
        {
            int leftHeight = maxDepth(root->left);
            int rightHeight = maxDepth(root->right);
            return max(leftHeight, rightHeight) + 1;
        }
    }
};
```

