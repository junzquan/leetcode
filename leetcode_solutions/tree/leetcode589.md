# [589. N叉树的前序遍历](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/)

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
    vector<int> preorder(Node* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    
    void preorder(Node* root, vector<int>& ans)
    {
        if (!root) return;
        ans.push_back(root->val);
        for (const auto& r : root->children)
            preorder(r, ans);
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
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        
        stack<Node*> s_;
        s_.push(root);
        while (!s_.empty())
        {
            const Node* node = s_.top();
            s_.pop();
            ans.push_back(node->val);
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it)
                s_.push(*it);                
        }
        
        return ans;
    }
};
```

