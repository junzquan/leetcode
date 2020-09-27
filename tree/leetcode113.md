# [113. 路径总和 II](https://leetcode-cn.com/problems/path-sum-ii/)

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> cur;
        pathSum(root, sum, cur, ans);
        return ans;
    }
    
private:
    void pathSum(TreeNode* node, int sum, vector<int>& cur, vector<vector<int>>& ans)
    {
        if (!node) return;
        if (!node->left && !node->right)
        {
            if (sum == node->val)
            {
                cur.push_back(node->val);
                ans.push_back(cur);
                cur.pop_back();
            }
            return;
        }
        
        cur.push_back(node->val);
        pathSum(node->left, sum - node->val, cur, ans);
        pathSum(node->right, sum - node->val, cur, ans);
        cur.pop_back();
    }
};
```

