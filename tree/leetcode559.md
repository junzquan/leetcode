# [559. N叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/)

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        if (root->children.empty()) return 1;
        int maxDep = 0;
        for (Node* node : root->children)
        {
            maxDep = max(maxDep, maxDepth(node));
        }
        return maxDep + 1;
    }
};
```

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(N)