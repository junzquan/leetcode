# [114. 二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)

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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }

private:
    TreeNode* pre = nullptr;
};
```

- 采用后序遍历的思想，不断更新节点的右孩子，并把左孩子置空。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(log N)