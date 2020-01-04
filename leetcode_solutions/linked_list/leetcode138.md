# [138. 复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/)

## 原地复制

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;

        Node* node = head;
        while (node != nullptr)
        {
            Node* copy = new Node(node->val, nullptr, nullptr);
            copy->next = node->next;
            node->next = copy;
            node = copy->next;
        }

        node = head;
        while (node != nullptr)
        {
            if (node->random != nullptr)
            {
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }

        node = head;
        Node* newHead = node->next;
        Node* newNode = newHead;
        while (node != nullptr)
        {
            node->next = node->next->next;
            if (newNode->next != nullptr)
            {
                newNode->next = newNode->next->next;
            }
            node = node->next;
            newNode = newNode->next;
        }

        return newHead;
    }
};
```

- 第一步，逐个复制节点并链接在原链表中；
- 第二步，复制原节点的 `random` 到新节点中；
- 第三部，分离新旧链表。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)



## 哈希表

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;

        Node* node = head;
        unordered_map<Node*, Node*> ma;
        while (node != nullptr)
        {
            Node* copy = new Node(node->val);
            ma[node] = copy;
            node = node->next;
        }

        node = head;
        while (node != nullptr)
        {
            ma[node]->next = ma[node->next];
            ma[node]->random = ma[node->random];
            node = node->next;
        }

        return ma[head];
    }
};
```

- 在哈希表中，键为原链表的节点的指针，值为新链表的节点的指针。

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(N)