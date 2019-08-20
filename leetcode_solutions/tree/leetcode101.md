# [101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/)

---

> 如果同时满足下面的条件，两个树互为镜像：
>
> 1. 它们的两个根结点具有相同的值。
> 2. 每个树的右子树都与另一个树的左子树镜像对称。

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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
    
    bool isMirror(TreeNode* t1, TreeNode* t2)
    {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return (t1->val == t2->val)
            && isMirror(t1->left, t2->right)
            && isMirror(t1->right, t2->left);
    }
};
```

---

## 迭代

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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q_;
        q_.push(root);
        q_.push(root);
        
        while (!q_.empty())
        {
            TreeNode* t1 = q_.front(); q_.pop();
            TreeNode* t2 = q_.front(); q_.pop();
            if (!t1 && !t2) continue;
            if (!t1 || !t2) return false;
            if (t1->val != t2->val) return false;
            q_.push(t1->left);
            q_.push(t2->right);
            q_.push(t1->right);
            q_.push(t2->left);
        }
        return true;
    }
};
```



