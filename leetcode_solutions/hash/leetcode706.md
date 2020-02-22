# [706. 设计哈希映射](https://leetcode-cn.com/problems/design-hashmap/)

```cpp
struct Node
{
    int key;
    int value;
    Node* next;
    Node(int key_, int value_): key(key_), value(value_), next(nullptr) {}
};
const int len = 100;

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap(): arr(vector<Node*>(len, nullptr)) {
        for (int i = 0; i < len; i++)
            arr[i] = new Node(-1, 0);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key % len;
        Node* temp = arr[index];
        while (temp)
        {
            if (temp->key == -1)
            {
                temp->key = key;
                temp->value = value;
                return;
            }
            if (temp->key == key)
            {
                temp->value = value;
                return;
            }
            if (temp->next == nullptr)
            {
                temp->next = new Node(key, value);
                return;
            }
            temp = temp->next;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key % len;
        Node* temp = arr[index];
        while (temp)
        {
            if (temp->key == key) return temp->value;
            temp = temp->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = key % len;
        Node* temp = arr[index];
        while (temp)
        {
            if (temp->key == key)
            {
                temp->value = 0;
                temp->key = -1;
                return;
            }
            temp = temp->next;
        }
    }

private:
    vector<Node*> arr;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
```

- 使用哈希函数，`key % len` 作为键值，当发生冲突时，利用链表在已有数据后面插入新的数据，即使用 `链地址法` 。



