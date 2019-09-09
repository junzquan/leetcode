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
    ListNode* rotateRight(ListNode* head, int k) {
    	if (!head || k == 0) return head;
        ListNode* tail = head;
        int cnt = 1;

        while (tail->next) {
        	tail = tail->next;
        	cnt++;
        }
        tail->next = head;
        //make linkedlist a cycle

        int move = k % cnt;
        tail = head;
        for (int i = 1; i != (cnt - move); i++) {
        	tail = tail->next;
        }
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};