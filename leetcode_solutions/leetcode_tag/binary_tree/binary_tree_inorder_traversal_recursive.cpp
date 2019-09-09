/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//recursive solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        inorder(root, res);
        return res;
    }

private:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) 
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};