# [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)

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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next && slow != fast)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return (fast == slow) ? true : false;
    }
};
```

