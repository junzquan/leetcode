# [669. 修剪二叉搜索树](https://leetcode-cn.com/problems/trim-a-binary-search-tree/)

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return nullptr;
        
        if (root->val > R) return trimBST(root->left, L, R);
        if (root->val < L) return trimBST(root->right, L, R);
        
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        
        return root;
    }
};
```

- `root->val > R`, 返回修剪后的左子树
- `root->val < L`, 返回修剪后的右子树
- `L <= root->val <= R`, 节点保留, 分别将向左右孩子要修剪后的子树