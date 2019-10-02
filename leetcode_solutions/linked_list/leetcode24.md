# [24. 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)

## 迭代

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* Thead = new ListNode(-1);
        Thead->next = head;
        ListNode* pre = Thead;
        
        while (pre->next && pre->next->next)
        {
            ListNode* a = pre->next;
            ListNode* b = pre->next->next;
            pre->next = b;
            a->next = b->next;
            b->next = a;
            pre = a;
        }
        
        return Thead->next;
    }
};
```



## 递归

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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};
```

- 不断向下一对要其`next`节点，直到下一对没有`head`节点或者只有`head`一个节点。