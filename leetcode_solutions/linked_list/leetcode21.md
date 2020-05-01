# [21. 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* node = &dummy;
        while (l1 && l2)
        {
            if (l1->val > l2->val)
            {
                node->next = l2;
                l2 = l2->next;
            }
            else
            {
                node->next = l1;
                l1 = l1->next;
            }
            node = node->next;
        }

        node->next = (l1 == nullptr) ? l2 : l1;

        return dummy.next;
    }
};
```

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)