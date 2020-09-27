# [652. 寻找重复的子树](https://leetcode-cn.com/problems/find-duplicate-subtrees/)

## 序列化

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> hash_map;
        serialize(root, res, hash_map);
        return res;
    }

private:
    string serialize(TreeNode* node, vector<TreeNode*>& res, unordered_map<string, int>& hash_map)
    {
        if (!node) return "#";
        string key = to_string(node->val) + "," 
                     + serialize(node->left, res, hash_map) + "," 
                     + serialize(node->right, res, hash_map);
        if (++hash_map[key] == 2) res.push_back(node);
        return key;
    }
};
```

- 将所有子树序列化，然后存入哈希表中，如果有重复的则加入结果。

### 复杂度分析

- 时间复杂度：O(N<sup>2</sup>)
- 空间复杂度：O(N<sup>2</sup>)



