# [450. 删除二叉搜索树中的节点](https://leetcode-cn.com/problems/delete-node-in-a-bst/)

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if      (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == nullptr) return root->right;
            if (root->right == nullptr) return root->left;
            // t为要删去的节点
            TreeNode* t = root;
            root = getMinNode(t->right);
            root->right = deleteMinNode(t->right);
            root->left = t->left;
            delete t;
        }
        return root;
    }

private:
    TreeNode* getMinNode(TreeNode* root)
    {
        if (root->left == nullptr) return root;
        return getMinNode(root->left);
    }

    TreeNode* deleteMinNode(TreeNode* root)
    {
        if (root->left == nullptr) return root->right;
        root->left = deleteMinNode(root->left);
        return root;
    }
};
```

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(H), H for height of BST