# [872. 叶子相似的树](https://leetcode-cn.com/problems/leaf-similar-trees/)

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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = new TreeNode(0);
        cur = head;
        inorder(root);
        return head->right;
    }

private:
    void inorder(TreeNode* node)
    {
        if (!node) return;
        inorder(node->left);
        cur->right = node;
        node->left = nullptr;
        cur = node;
        inorder(node->right);
    }

    TreeNode* cur;
};
```

- 当遍历到一个节点时，将其左孩子设为空，并把该节点作为上一个节点的右孩子。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(H)

