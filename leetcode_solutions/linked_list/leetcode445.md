# [445. 两数相加 II](https://leetcode-cn.com/problems/add-two-numbers-ii/)

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
        if (l1->val == 0) return l2;
        if (l2->val == 0) return l1;
        const ListNode* const h1 = l1;
        const ListNode* const h2 = l2;
        stack<ListNode*> s1, s2;
        
        while (l1 || l2)
        {
            if (l1)
            {
                s1.push(l1);
                l1 = l1->next;
            }
            if (l2)
            {
                s2.push(l2);
                l2 = l2->next;
            }
        }
        
        ListNode* curHead = nullptr;
        int carry = 0;
        while (!s1.empty() || !s2.empty())
        {
            int cur1 = 0;
            if (!s1.empty())
            {
                cur1 = s1.top()->val;
                s1.pop();
            }
            int cur2 = 0;
            if (!s2.empty())
            {
                cur2 = s2.top()->val;
                s2.pop();
            }
            int curSum = cur1 + cur2 + carry;
            ListNode* temp = new ListNode(curSum % 10);
            carry = curSum / 10;
            temp->next = curHead;
            curHead = temp;
        }
        
        if (carry != 0)
        {
            ListNode* temp = new ListNode(carry);
            temp->next = curHead;
            curHead = temp;
        }
        
        return curHead;
    }
};
```

- 使用两个栈