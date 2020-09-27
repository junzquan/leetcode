# [102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty())
        {
            vector<int> temp;

            int levelNum = q.size();
            for (int i = 0; i != levelNum; i++)
            {
                TreeNode* curNode = q.front();
                temp.push_back(curNode->val);
                q.pop();
                if (curNode->left) q.push(curNode->left);
                if (curNode->right) q.push(curNode->right);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};


```

