# [111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)

---

## BFS

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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q_;
        q_.push(make_pair(root, 1));
        while (true)
        {
            TreeNode* node = q_.front().first;
            int level = q_.front().second;
            q_.pop();
            if (!node->left && !node->right) return level;
            if (node->left)
                q_.push(make_pair(node->left, level + 1));
            if (node->right)
                q_.push(make_pair(node->right, level + 1));
        }
    }
};
```

---

## 递归

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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        if (!root->right)
            return minDepth(root->left) + 1;
        if (!root->left)
            return minDepth(root->right) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
```

