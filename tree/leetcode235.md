# [235. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

## 递归

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        
        int parentVal = root->val;
        int pVal = p->val;
        int qVal = q->val;

        if (pVal > parentVal && qVal > parentVal)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (pVal < parentVal && qVal < parentVal)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            return root;
        }
    }
};
```

- 当 `p` 的值和 `q` 的值都大于节点 `root` 的值时，向右子树寻找；
- 当 `p` 的值和 `q` 的值都小于节点 `root` 的值时，向左子树寻找；
- 其余情况则是找到了最近公共祖先 `root` 。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(N)



## 迭代

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;

        int pVal = p->val;
        int qVal = q->val;
        TreeNode* node = root;

        while (node != nullptr)
        {
            int parentVal = node->val;
            
            if (pVal > parentVal && qVal > parentVal) 
            {
                node = node->right;
            }
            else if (pVal < parentVal && qVal < parentVal) 
            {
                node = node->left;
            }
            else 
            {
                return node;
            }
        }
        return root;
    }
};
```

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)