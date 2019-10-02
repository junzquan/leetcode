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
        ListNode* slow = head;
        ListNode* fast = head;
        while (true)
        {
            if (!fast || !fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        return true;
    }
};
```

