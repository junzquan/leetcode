# [687. 最长同值路径](https://leetcode-cn.com/problems/longest-univalue-path/)

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
    int longestUnivaluePath(TreeNode* root) {
        int length = 0;
        dfs(length, root);
        return length;
    }

private:
    int dfs(int& length, TreeNode* node)
    {
        if (node == nullptr) return 0;

        int left  = dfs(length, node->left);
        int right = dfs(length, node->right);

        int len_left  = 0;
        int len_right = 0;
        if (node->left && node->val == node->left->val)
        {
            len_left = left + 1;
        }
        if (node->right && node->val == node->right->val)
        {
            len_right = right + 1;
        }
        length = max(len_left + len_right, length);
        return max(len_left, len_right);
    }
};
```

- 自底向上求解，对于任意节点 `node` ，递归调用函数 `dfs` 分别求得左子树和右子树的最长同值路径（写代码时先不管 `dfs` 实现细节，直接假设 `dfs` 可以成功求出结果）；
- 然后判断节点 `node` 的值和左孩子的值是否相等，如果相等，令左边同值路径的值`len_left = left + 1`，否则 `len_left` 为 `0`， 相当于这条路径断了；同理可得右边同值路径的值 `len_right`；
- 最后更新最长同值路径的值 `length` 并返回左边和右边同值路径的最大值。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(log N)