/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

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
        ListNode dummy(0);
        ListNode* resultPtr = &dummy;
        int single = 0, carry = 0;
        
        while (l1 != NULL || l2 != NULL) {
            int val1 = 0, val2 = 0;
            if (l1 != NULL)
                val1 = l1->val;
            if (l2 != NULL)
                val2 = l2->val;
            
            single = val1 + val2 + carry;
            if (single >= 10) {
                single = single % 10;
                carry = 1;
            } else {
                carry = 0;
            }
            
            ListNode* add = new ListNode(single);
            resultPtr->next = add;
            resultPtr = resultPtr->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        
        if (carry == 1) {
            ListNode* add = new ListNode(1);
            resultPtr->next = add;
        }
        
        return dummy.next;
    }
};

int main() {
    ListNode* n1 = new ListNode(9);
    //ListNode* n2 = new ListNode(4, n3);
    //ListNode* n1 = new ListNode(2, n2);
    
    ListNode* m10 = new ListNode(9);
    ListNode* m9 = new ListNode(9, m10);
    ListNode* m8 = new ListNode(9, m9);
    ListNode* m7 = new ListNode(9, m8);
    ListNode* m6 = new ListNode(9, m7);
    ListNode* m5 = new ListNode(9, m6);
    ListNode* m4 = new ListNode(9, m5);
    ListNode* m3 = new ListNode(9, m4);
    ListNode* m2 = new ListNode(9, m3);
    ListNode* m1 = new ListNode(1, m2);
    
    Solution s;
    s.addTwoNumbers(n1, m1);
    
    
    
    return 0;
}
