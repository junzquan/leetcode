# [103. 二叉树的锯齿形层次遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        stack<TreeNode*> s1;  // left to right
        stack<TreeNode*> s2;  // right to left
        s1.push(root);

        while (!s1.empty() || !s2.empty())
        {
            vector<int> curLevelVals;
            TreeNode* cur = nullptr;

            if (!s1.empty())
            {
                while (!s1.empty())
                {
                    cur = s1.top();
                    s1.pop();
                    curLevelVals.push_back(cur->val);
                    if (cur->left != nullptr) s2.push(cur->left);
                    if (cur->right != nullptr) s2.push(cur->right);
                }
                res.push_back(curLevelVals);
            }
            else
            {
                while (!s2.empty())
                {
                    cur = s2.top();
                    s2.pop();
                    curLevelVals.push_back(cur->val);
                    if (cur->right != nullptr) s1.push(cur->right);
                    if (cur->left != nullptr) s1.push(cur->left);
                }
                res.push_back(curLevelVals);
            }
        }

        return res;
    }
};
```

- 使用两个栈 `s1` 和 `s2` ：`s1` 存储从左往右的节点， `s2` 存储从右往左的节点；
- 当遍历栈 `s1` 时，将左右孩子（如果存在）先后压入栈 `s2` 中，那么栈 `s2` 的弹出顺序就是从右到左的；
- 遍历 `s2` 时，则进行相反的操作。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(log N)