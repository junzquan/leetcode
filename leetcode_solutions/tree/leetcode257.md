# [257. 二叉树的所有路径](https://leetcode-cn.com/problems/binary-tree-paths/)

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s;
        dfs(res, root, s);
        return res;
    }

private:
    void dfs(vector<string>& res, TreeNode* node, string s)
    {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr)
        {
            res.push_back(s + to_string(node->val));
            return;
        }
        dfs(res, node->left, s + to_string(node->val) + "->");
        dfs(res, node->right, s + to_string(node->val) + "->");
        return;
    }
};
```

- 自顶向下，对任意非叶子节点，让 `s ` 加上当前节点的值 `node->val` ，然后递归搜索左子树和右子树；
- 对任意叶子结点，直接将 `s + node->val` 加入结果 `res`  。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(log N)