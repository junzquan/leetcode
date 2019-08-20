# [94. 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)

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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root)
        {
            inorderTraversal(root->left);
            ans.push_back(root->val);
            inorderTraversal(root->right);
        }
        return ans;
    }
    
private:
    vector<int> ans;
};
```

---

## 迭代(stack)

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s_;
        TreeNode* cur = root;
        while (cur || !s_.empty())
        {
            while (cur)
            {
                s_.push(cur);
                cur = cur->left;
            }
            
            if (!s_.empty())
            {
                ans.push_back(s_.top()->val);
                cur = s_.top()->right;
                s_.pop();
            }
        }
        return ans;
    }
};
```



