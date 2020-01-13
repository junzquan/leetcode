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
        vector<int> ans;
        inorderTraversal(root, ans);
        return ans;
    }

private:
    void inorderTraversal(TreeNode* node, vector<int>& ans)
    {
        if (node == nullptr) return;
        inorderTraversal(node->left, ans);
        ans.push_back(node->val);
        inorderTraversal(node->right, ans);
    }
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



## 迭代2（颜色标记法）

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
        const int WHITE = 0;
        const int GRAY = 1;
        stack<pair<int, TreeNode*>> s;
        s.push(make_pair(WHITE, root));
        vector<int> res;
        
        while (!s.empty())
        {
            int color = s.top().first;
            TreeNode* node = s.top().second;
            s.pop();
            if (node == nullptr) continue;
            if (color == WHITE)
            {
                s.push(make_pair(WHITE, node->right));
                s.push(make_pair(GRAY, node));
                s.push(make_pair(WHITE, node->left));
            }
            else
            {
                res.push_back(node->val);
            }
        }

        return res;
    }
};
```

- 使用颜色标记节点状态， `WHITE` 表示新加入的节点，`GRAY` 表示已访问的节点；
- 如果遇到的节点为 `WHITE`，则分别将其右孩子、自身和左孩子压入栈中；
- 如果遇到的节点为 `GRAY`， 则把值加入答案 `ans` 。

