# [428. 序列化和反序列化 N 叉树](https://leetcode-cn.com/problems/serialize-and-deserialize-n-ary-tree/)

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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";
        string res = to_string(root->val) + "{";
        for (auto node : root->children)
            res += serialize(node) + ",";
        if (res.back() == ',')
            res.pop_back();
        res += "}";
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        string val;
        Node* head = nullptr;
        stack<Node*> s;
        for (int i = 0; i < data.length(); i++)
        {
            const char& c = data[i];
            if ((c >= '0' && c <= '9'))
            {
                val += c;
            }
            else if (c == '{')
            {
                Node* node = new Node(stoi(val));
                if (!head) head = node;
                s.push(node);
                val.clear();
            }
            else if (c == '}')
            {
                Node* node = s.top();
                s.pop();
                if (!s.empty())
                {
                    Node* prev_node = s.top();
                    prev_node->children.push_back(node);
                }
            }            
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```

