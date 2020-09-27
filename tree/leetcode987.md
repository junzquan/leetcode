# [987. 二叉树的垂序遍历](https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/)

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        traversal(root, 0, 0);
        
        for (auto& p : m)
        {
            vector<int> temp;
            for (auto& h : p.second)
            {
                for (auto value : h.second)
                {
                    temp.push_back(value);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
    
private:
    map<int, map<int, multiset<int>>> m;
    void traversal(TreeNode* node, int pos, int height)
    {
        if (!node)
            return;
        m[pos][height].insert(node->val);
        traversal(node->left, pos - 1, height + 1);
        traversal(node->right, pos + 1, height + 1);
    }
};
```

- `map`可自动排序，在添加新节点时，按照`map[position][height].insert(node->val)`添加，最后得到的map是从左到右，从上到下存储节点的；当位置相同时，由于使用了`multiset`，值是从小到大排序的。
- 注意使用`height + 1`，这样在第二个`map`中节点才可以自上而下排序。