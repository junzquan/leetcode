# [606. 根据二叉树创建字符串](https://leetcode-cn.com/problems/construct-string-from-binary-tree/)

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
    string tree2str(TreeNode* t) {
        string res;
        if (!t) return res;

        res.append(to_string(t->val));
        if (!t->left && !t->right) 
            return res;

        if (t->left) 
            res.append("(" + tree2str(t->left) + ")");
        else 
            res.append("()");

        if (t->right) 
            res.append("(" + tree2str(t->right) + ")");
        return res;
    }
};
```

共有4种情况：

- `t` 为空节点，返回空字符串；
- `t` 是叶子节点，返回叶子节点的值 ；
- `t` 有左子树，向结果字符串添加 `( 左子树的结果 )` ，否则添加 `()` ；
- `t` 有右子树，向结果字符串添加 `( 右子树的结果 )`。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(N)