#include <iostream>

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() : head(nullptr), tail(nullptr), size(0){}
    
    ~MyLinkedList() {
        ListNode* node = head;
        while (node) {
            ListNode* cur = node;
            node = node->next;
            delete cur;
        }
        head = nullptr;
        tail = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode* node = head;
        while (index--)
            node = node->next;
        return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* temp = new ListNode(val, nullptr, head);
        if (size == 0) {
            tail = temp;
        } else {
            head->prev = temp;
        }
        head = temp;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* node = new ListNode(val, tail, nullptr);
        if (size++ == 0)
            head = tail = node;
        else {
            tail->next = node;
            tail = tail->next;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (size == 0 && index != 0) return;
        if (index == 0) return addAtHead(val);
        if (index == size) return addAtTail(val);
        ListNode dummy(0, nullptr, head);
        ListNode* prevNode = &dummy;
        while (index--)
            prevNode = prevNode->next;
        ListNode* add = new ListNode(val, prevNode, prevNode->next);
        prevNode->next->prev = add;
        prevNode->next = add;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        ListNode* cur = head;
        int n = index;
        while (n--)
            cur = cur->next;
        if (index == 0) {
            head = head->next;
            head->next->prev = nullptr;
        } else if (index == size-1) {
            tail = cur->prev;
            cur->prev->next = nullptr;
        } else {
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
        }
        ListNode* nodeDelete = cur;
        delete nodeDelete;
        size--;
    }
    
private:
    struct ListNode
    {
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode(int val_) : val(val_), prev(nullptr), next(nullptr) {}
        ListNode(int val_, ListNode* prev_, ListNode* next_) :
        val(val_), prev(prev_), next(next_) {}
    };
    ListNode* head;
    ListNode* tail;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */

int main(int argc, const char * argv[]) {
    MyLinkedList linkedList;
    linkedList.addAtHead(1);
    linkedList.addAtIndex(1, 2);
    int i = linkedList.get(1);
    int j = linkedList.get(0);
    int k = linkedList.get(2);
    std::cout << i << " " << j << " " << k << std::endl;
    
    return 0;
}

