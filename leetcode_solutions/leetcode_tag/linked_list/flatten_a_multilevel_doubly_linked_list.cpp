/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;
        Node* radar = head;
        Node* childRadar = NULL;
        
        while (radar) {
            if (!radar->child) {
                radar = radar->next;
                continue;
            }
            //no child

            childRadar = radar->child;
            while (childRadar->next) {
                childRadar = childRadar->next;
            }
            childRadar->next = radar->next;
            if (radar->next)
                childRadar->next->prev = childRadar;
            radar->next = radar->child;
            radar->child->prev = radar;
            radar->child = NULL;
        }

        return head;
    }
};