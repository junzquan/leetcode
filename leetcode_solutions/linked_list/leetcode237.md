# [237. 删除链表中的节点](https://leetcode-cn.com/problems/delete-node-in-a-linked-list/)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* del = node->next;
        node->next = node->next->next;
        delete del;
    }
};
```

- 由于不知道头结点，所以无法得知 `node` 的上一节点，但是可以知道 `node` 的下一节点，于是将 `node` 的下一节点的值赋给 `node` 节点，然后让 `node` 的 `next` 指针指向其下下个节点，最后 `delete` 废弃节点即可。

### 复杂度分析

- 时间复杂度：O(1)
- 空间复杂度：O(1)