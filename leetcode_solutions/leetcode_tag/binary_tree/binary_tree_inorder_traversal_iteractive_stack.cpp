/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//iterative solution using stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        stack<TreeNode*> nodeStack;
        TreeNode* cur = root;
        while (cur || !nodeStack.empty()) {
        	if (cur) {
        		nodeStack.push(cur);
        		cur = cur->left;
        	} else {
        		cur = nodeStack.top();
        		nodeStack.pop();
        		res.push_back(cur->val);
        		cur = cur->right;
        	}
        }
        return res;
    }
};