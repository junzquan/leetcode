# [572. 另一个树的子树](https://leetcode-cn.com/problems/subtree-of-another-tree/)

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (t == nullptr) return true;
        if (s == nullptr) return false;
        if (isEqual(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
private:
    bool isEqual(TreeNode* s, TreeNode* t)
    {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        return (s->val == t->val)
            && isEqual(s->left, t->left)
            && isEqual(s->right, t->right);
    }
};
```

