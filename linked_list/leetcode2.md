# [2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/)

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return nullptr;
        if (!l1 && l2) return l2;
        if (l1 && !l2) return l1;
        int sum = l1->val + l2->val;
        ListNode* head = new ListNode(sum % 10);
        ListNode* cur = head;
        int carry = (sum > 9) ? (sum / 10) : 0;
        l1 = l1->next;
        l2 = l2->next;
        
        while (l1 || l2)
        {
            sum = 0;
            if (l1) 
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) 
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            cur->next = new ListNode(sum % 10);
            carry = (sum > 9) ? (sum / 10) : 0;
            cur = cur->next;
        }
        if (carry > 0)
            cur->next = new ListNode(carry);
        
        return head;
    }
};
```



