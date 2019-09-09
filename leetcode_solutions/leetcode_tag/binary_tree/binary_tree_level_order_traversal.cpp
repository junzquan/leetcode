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
        vector<vector<int>> res;
        std::vector<int> level;
        queue<TreeNode*> q;
        if (!root)
        	return res;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
        	TreeNode* temp = q.front();
        	q.pop();
        	if (temp == NULL) {
        		res.push_back(level);
        		level.resize(0);
        		if (q.size() > 0)
        			q.push(NULL);
        	} else {
        		level.push_back(temp->val);
        		if (temp->left) q.push(temp->left);
        		if (temp->right) q.push(temp->right);
        	}
        }
        return res;
    }
};