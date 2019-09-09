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
    TreeNode* deleteNode(TreeNode* root, int key) {
      if (!root) return nullptr;

      TreeNode* left = deleteNode(root->left, key);
      TreeNode* right = deleteNode(root->right, key);

      if (root->val == key) 
      {
      	delete root;
      	TreeNode* tmp = right;
      	while (tmp && tmp->left)
        	tmp = tmp->left;
      	if (tmp) 
      	{
      		tmp->left = left;
      		return right;
      	}
      	return left; 
      }

      root->left = left;
      root->right = right;
      return root;
    }
};