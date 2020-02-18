# [1022. 从根到叶的二进制数之和](https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers/)

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
    int sumRootToLeaf(TreeNode* root) {
        return root ? traversal(root, 0) : 0;
    }
    
private:
    int traversal(TreeNode* node, int num)
    {
        int sum = 0;
        num = (num << 1) + node->val;
        if (!node->left && !node->right) return num;
        if (node->left) sum += traversal(node->left, num);
        if (node->right) sum += traversal(node->right, num);
        return sum;
    }
};
```

## 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(H)