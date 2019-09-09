/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Morris Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        TreeNode* cur = root;
        while (cur) {
        	if (cur->left) {
        		TreeNode* pre = cur->left;
        		while (pre->right && (pre->right != cur)) 
        			pre = pre->right;
        		if (!(pre->right)) {
        			pre->right = cur;
        			cur = cur->left;
        		} else {
        			pre->right = NULL;
        			res.push_back(cur->val);
        			cur = cur->right;
        		}
        	} else {
        		res.push_back(cur->val);
        		cur = cur->right;
        	}
        }
        return res;
    }
};