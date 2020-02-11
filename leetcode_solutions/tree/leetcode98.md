# [98. 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)

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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool isValidBST(TreeNode* root, long minVal, long maxVal)
    {
        if (root == nullptr) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return isValidBST(root->left, minVal, root->val) 
            && isValidBST(root->right, root->val, maxVal);
    }
};
```

- 缺点是使用了 `LLONG_MIN` 和 `LLONG_MAX` 。

## 递归(better)

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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }

private:
    bool isValidBST(TreeNode* root, int* minValPtr, int* maxValPtr)
    {
        if (root == nullptr) return true;
        if ((minValPtr != nullptr && root->val <= *minValPtr) 
          ||(maxValPtr != nullptr && root->val >= *maxValPtr))
            return false;
        return isValidBST(root->left, minValPtr, &root->val) 
            && isValidBST(root->right, &root->val, maxValPtr);
    }
};
```

---

## 中序遍历(迭代)

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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> sta;
        TreeNode* cur = root;
        TreeNode* preNode = nullptr;

        while (!sta.empty() || cur != nullptr)
        {
            while (cur != nullptr)
            {
                sta.push(cur);
                cur = cur->left;
            }
            cur = sta.top();
            sta.pop();
            if (preNode != nullptr && cur->val <= preNode->val) return false;
            preNode = cur;
            cur = cur->right;
        }

        return true;
    }
};
```

## 中序遍历(递归)

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
    bool isValidBST(TreeNode* root) {
        return inorderTraversal(root);
    }

private:
    TreeNode* preNode;
    bool inorderTraversal(TreeNode* root)
    {
        if (!root) return true;
        if (!inorderTraversal(root->left)) return false;
        if (preNode && root->val <= preNode->val) return false;
        preNode = root;
        return inorderTraversal(root->right);
    }
};
```



### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(h)

