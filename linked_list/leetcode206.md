# [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

## 递归

``` cpp
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
    ListNode* reverseList(ListNode* head) {
        // 当前节点或者当前节点的下一个节点为空时 返回当前节点
        if (!head || !head->next) return head;

        // 递归获得新链表的头节点
        ListNode* newHead = reverseList(head->next);

        // 将下一个节点指向当前节点
        head->next->next = head;

        // 将当前节点的next指针置空
        head->next = nullptr;

        // 返回新的头节点(注意每次调用返回的newHead都是相同的)
        return newHead;
    }
};
```

### 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(N)



## 迭代

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;

        while (cur)
        {
            // 先保存当前节点的下一个节点的指针
            ListNode* tempNext = cur->next;

            // 将当前节点的下一个节点的指针指向前一个节点
            cur->next = pre;

            // 更新pre
            pre = cur;

            // 更新cur
            cur = tempNext;
        }

        return pre;
    }
};
```

## 复杂度分析

- 时间复杂度：O(N)
- 空间复杂度：O(1)