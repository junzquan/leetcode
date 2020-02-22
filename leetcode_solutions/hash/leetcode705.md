# [705. 设计哈希集合](https://leetcode-cn.com/problems/design-hashset/)

```cpp
struct Node
{
    int val;
    Node* next;
    Node(int val): val(val), next(nullptr) {}
};
const int len = 100;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        arr = vector<Node*>(len);
        for (int i = 0; i < len; i++)
        {
            Node* node = new Node(-1);
            arr[i] = node;
        }
    }
    
    void add(int key) {
        int hashVal = key % len;
        Node* temp = arr[hashVal];
        if (temp->val != -1)
        {
            while (temp)
            {
                if (temp->val == key) return;
                if (!(temp->next))
                {
                    Node* node = new Node(key);
                    temp->next = node;
                    return;
                }
                temp = temp->next;
            }
        }
        else
        {
            temp->val = key;
            return;
        }
    }
    
    void remove(int key) {
        int hashVal = key % len;
        Node* temp = arr[hashVal];
        if (temp->val != -1)
        {
            while (temp)
            {
                if (temp->val != key) temp = temp->next;
                else
                {
                    temp->val = -1;
                    return;
                }
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hashVal = key % len;
        Node* temp = arr[hashVal];
        while (temp)
        {
            if (temp->val == key) return true;
            temp = temp->next;
        }
        return false;
    }

private:
    vector<Node*> arr;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```

- 使用哈希函数，`key % len` 作为键值，当发生冲突时，利用链表在已有数据后面插入新的数据，即使用 `链地址法` 。



