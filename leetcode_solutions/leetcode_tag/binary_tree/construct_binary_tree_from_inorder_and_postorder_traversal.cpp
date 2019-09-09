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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if (postorder.empty())
        	return NULL;
        idx = postorder.size() - 1;
        return build(inorder, postorder, 0, idx);
    }

private:
	int idx;
	TreeNode* build(vector<int>& inorder, vector<int>& postorder,
		int start, int end)
	{
		if (start > end)
			return NULL;
		TreeNode* mid = new TreeNode(postorder[idx--]);
		if (start == end)
			return mid;
		int index = search(inorder, mid, end);
		mid->right = build(inorder, postorder, index + 1, end);
		mid->left = build(inorder, postorder, start, index - 1);
		return mid;
	}

	int search(vector<int>& inorder, TreeNode* mid, int end)
	{
		for (int i = end; i > 0; i--)
		{
			if (inorder[i] == mid->val)
				return i;
		}
		return 0;
	}
};