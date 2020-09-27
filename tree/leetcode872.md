# [872. 叶子相似的树](https://leetcode-cn.com/problems/leaf-similar-trees/)

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1;
        vector<int> vec2;
        getLeaves(root1, vec1);
        getLeaves(root2, vec2);
        return sameVec(vec1, vec2);
    }
    
private:
    void getLeaves(TreeNode* root, vector<int>& vec)
    {
        if (!root) return;
        if (!root->left && !root->right)
        {
            vec.push_back(root->val);
            return;
        }
        getLeaves(root->left, vec);
        getLeaves(root->right, vec);
    }
    
    bool sameVec(vector<int>& vec1, vector<int>& vec2)
    {
        if (vec1.size() != vec2.size())
            return false;
        for (int i = 0; i != vec1.size(); i++)
            if (vec1[i] != vec2[i])
                return false;
        return true;
            
    }
};
```

