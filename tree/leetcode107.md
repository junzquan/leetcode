# [107. 二叉树的层次遍历 II](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/)

```cpp
/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (48.34%)
 * Likes:    847
 * Dislikes: 162
 * Total Accepted:    250.3K
 * Total Submissions: 517.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        stack<vector<int>> s;
        q.push(root);
        
        while (!q.empty())
        {
            vector<int> level;
            const int levelNum = q.size();
            TreeNode* curNode = nullptr;

            for(int i = 0; i != levelNum; i++)
            {
                curNode = q.front();
                level.push_back(curNode->val);
                q.pop();
                if (curNode->left) q.push(curNode->left);
                if (curNode->right) q.push(curNode->right);
            }
            s.push(level);
        }

        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};


```

