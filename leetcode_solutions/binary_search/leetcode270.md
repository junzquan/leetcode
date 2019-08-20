# [270. 最接近的二叉搜索树值](https://leetcode-cn.com/problems/closest-binary-search-tree-value/)

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
    int closestValue(TreeNode* root, double target) {
        if (target > root->val)
        {
            if (!root->right)
                return root->val;
            else
            {
                double diff = abs(target - root->val);
                int rightMin = closestValue(root->right, target);
                double rightDiff = abs(rightMin - target);
                return diff < rightDiff ? root->val : rightMin;
            }
        }
        else
        {
            if (!root->left)
                return root->val;
            else
            {
                double diff = abs(target - root->val);
                int leftMin = closestValue(root->left, target);
                double leftDiff = abs(leftMin - target);
                return diff < leftDiff ? root->val : leftMin;
            }
        }
    }
};
```

- 如果`target > root->val`，与右子节点 比较，否则与左子节点比较