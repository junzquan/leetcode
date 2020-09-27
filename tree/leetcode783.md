# [783. 二叉搜索树结点最小距离](https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/)

## 中序遍历

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
    int minDiffInBST(TreeNode* root) {
        res = INT_MAX;
        prev = nullptr;
        inorder(root);
        return res;
    }

private:
    void inorder(TreeNode* root)
    {
        if (!root) return;
        inorder(root->left);
        if (prev) res = min(res, abs(root->val - *prev));
        prev = &root->val;
        inorder(root->right);
    }

    int* prev;
    int res;
};
```

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(H)