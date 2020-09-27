# [701. 二叉搜索树中的插入操作](https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/)

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        else                 root->right = insertIntoBST(root->right, val);
        return root;
    }
};
```

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(H), H for height of BST