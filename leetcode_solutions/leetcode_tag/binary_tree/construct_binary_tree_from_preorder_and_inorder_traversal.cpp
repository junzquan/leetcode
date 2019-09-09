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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
        	return NULL;
        idx = 0;
        return build(preorder, inorder, idx, preorder.size() - 1);
    }

private:
	int idx;
	TreeNode* build(vector<int>& preorder, vector<int>& inorder,
		int start, int end)
	{
		if (start > end)
			return NULL;
		TreeNode* mid = new TreeNode(preorder[idx++]);
		if (start == end)
			return mid;
		int index = search(inorder, mid, end);
		mid->left = build(preorder, inorder, start, index - 1);
		mid->right = build(preorder, inorder, index + 1, end);
		return mid;
	}

	int search(vector<int>& inorder, TreeNode* mid, int end)
	{
		for (; end > 0; end--)
		{
			if (inorder[end] == mid->val)
				return end;
		}
		return 0;
	}
};