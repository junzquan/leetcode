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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        if (root == NULL)
        	return res;
        stack<TreeNode *> treeStack;
        treeStack.push(root);
        while (!treeStack.empty()) {
        	TreeNode *curNode = treeStack.top();
        	res.push_back(curNode->val);
        	treeStack.pop();
        	if (curNode->right) 
        		treeStack.push(curNode->right);
        	if (curNode->left)
        		treeStack.push(curNode->left);
        }
        return res;
    }
};