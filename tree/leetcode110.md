# [110. 平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree/)

---

## 自顶向下

最坏情况下时间复杂度为O(N^2)

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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right); 
    }
    
private:
    int depth(TreeNode* root)
    {
        if (!root) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
};
```

---

## 自底向上

最坏情况下为O(N)

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
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
    
private:
    int depth(TreeNode* root)
    {
        if (!root) return 0;
        int left = depth(root->left);
        if (left == -1) return -1;
        int right = depth(root->right);
        if (right == -1) return -1;
        return (left - right) <= 1 ? max(left, right) + 1 : -1;
    }
};
```

