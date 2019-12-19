# [108. 将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r)
    {
        if (l > r) return nullptr;
        int mid = l + (r - l + 1) / 2;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = sortedArrayToBST(nums, l, mid - 1);
        cur->right = sortedArrayToBST(nums, mid + 1, r);
        return cur;
    }
};
```

- 将数组二分，分别递归构建左子树和右子树。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(log N)