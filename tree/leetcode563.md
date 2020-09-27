# [563. 二叉树的坡度](https://leetcode-cn.com/problems/binary-tree-tilt/)

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
    int findTilt(TreeNode* root) {
        int res = 0;
        traversal(root, res);
        return res;
    }

private:
    int traversal(TreeNode* root, int& res)
    {
        if (!root) return 0;
        int left = traversal(root->left, res);
        int right = traversal(root->right, res);
        res += abs(left - right);
        return left + right + root->val;
    }
};
```

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(N)