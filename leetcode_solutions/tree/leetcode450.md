# [450. 删除二叉搜索树中的节点](https://leetcode-cn.com/problems/delete-node-in-a-bst/)

## 迭代

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* currentNode = root;
        TreeNode* parentNode = nullptr;
        while (currentNode)
        {
            if (key < currentNode->val)
            {
                parentNode = currentNode;
                currentNode = currentNode->left;
            }
            else if (key > currentNode->val)
            {
                parentNode = currentNode;
                currentNode = currentNode->right;
            }
            else
            {
                if (currentNode->left && currentNode->right)
                {
                    TreeNode* min_node_parent = currentNode;
                    TreeNode* min_node = getMinNode(currentNode->right, min_node_parent);
                    currentNode->val = min_node->val;
                    if (min_node_parent->left == min_node) 
                        min_node_parent->left = min_node->left ? min_node->left : min_node->right;
                    else if (min_node_parent->right == min_node) 
                        min_node_parent->right = min_node->left ? min_node->left : min_node->right;
                }
                else if (!parentNode)
                {
                    root = currentNode->left ? currentNode->left : currentNode->right;
                }
                else if (parentNode->left == currentNode)
                {
                    parentNode->left = currentNode->left ? currentNode->left : currentNode->right;
                }
                else if (parentNode->right == currentNode)
                {
                    parentNode->right = currentNode->left ? currentNode->left : currentNode->right;
                }
                break;
            }
        }

        return root;
    }

    TreeNode* getMinNode(TreeNode* root, TreeNode*& parent)
    {
        while (root->left)
        {
            parent = root;
            root = root->left;
        }
        return root;
    }
};
```



## 递归

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // key比当前节点的值小则向左子树搜索
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        // key比当前节点的值大则向右子树搜索
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        // key等于当前节点的值
        else
        {
            // 当前节点没有左子树
            if (!root->left)
            {
                return root->right;
            }
            // 当前节点没有右子树
            else if (!root->right)
            {
                return root->left;
            }
            // 当前节点既有左子树又有右子树
            else
            {
                TreeNode* node = root->right;
                // 找到当前节点的右子树的最小节点
                while (node->left)
                {
                    node = node->left;
                }
                // 将root节点的左子树放到最小节点的左子树上
                node->left = root->left;
                return root->right;
            }
        }

        return root;
    }
};
```

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(H), H for height of BST