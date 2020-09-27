# [590. N叉树的后序遍历](https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/)

---

## 递归

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
    
    void postorder(Node* root, vector<int>& ans)
    {
        if (!root) return;
        for (const auto& node : root->children)
            postorder(node, ans);
        ans.push_back(root->val);        
    }
};
```

---

## 迭代

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<Node*> s_;
        s_.push(root);
        
        while (!s_.empty())
        {
            const Node* node = s_.top();
            s_.pop();
            ans.push_back(node->val);
            for (const auto& child : node->children)
                s_.push(child);
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```

- 按 根-右-左 遍历树，`vector`的反序为后序遍历