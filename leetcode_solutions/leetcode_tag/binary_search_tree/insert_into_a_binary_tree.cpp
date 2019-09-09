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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *insertNode = new TreeNode(val);
        searchBST(insertNode, root, val);
        return root;
    }

private:
	TreeNode* searchBST(TreeNode *insertNode, TreeNode *root, int val)
	{
		if (!root->right && val > root->val)
		{
			root->right = insertNode;
			return insertNode;
		}
		else if (!root->left && val < root->val)
		{
			root->left = insertNode;
			return insertNode;
		}
		else
			return (val > root->val) ? searchBST(insertNode, root->right, val) : searchBST(insertNode, root->left, val);
	}

public:
	TreeNode* insertIntoBST_secondVersion(TreeNode* root, int val) {
        if (!root)
        {
            TreeNode *insertNode = new TreeNode(val);
            return insertNode;
        }
        else if (val > root->val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        else
        {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};