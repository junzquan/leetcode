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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return NULL;
        if (!l1 || !l2) {
            ListNode* head = NULL;
            (l1 == NULL) ? (head = l2) : (head = l1);
            return head;
        }
        
        ListNode* head = nullptr;
        ListNode* n = nullptr;
        if ((l1->val) > (l2->val)) {
            n = l2;
            l2 = l1;
            l1 = n;
            head = l1;
        } else {
            head = l1;
        }
        
        while (l1 && l2) {
            if (l1->next == nullptr) {
                n = l1;
                l1 = l1->next;
                n->next = l2;
            } else if (l1->val <= l2->val && l2->val <= l1->next->val) {
                n = l2->next;
                l2->next = l1->next;
                l1->next = l2;
                l1 = l1->next;
                l2 = n;
            } else {
                l1 = l1->next;
            }
        }
        return head;
    }
};

int main() {
    //ListNode* n3 = new ListNode(4);
    //ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(2);
    
    //ListNode* m3 = new ListNode(4);
    //ListNode* m2 = new ListNode(3, m3);
    ListNode* m1 = new ListNode(1);
    
    Solution s;
    s.mergeTwoLists(n1, m1);
    
    
    
    return 0;
}
