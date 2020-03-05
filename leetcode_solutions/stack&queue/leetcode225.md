# [225. 用队列实现栈](https://leetcode-cn.com/problems/implement-stack-using-queues/)

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack(): que(queue<int>()) {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (que.empty()) return -1;
        queue<int> tempQue;
        int que_size = que.size();
        for (int i = 0; i < que_size - 1; i++)
        {
            int front = que.front();
            que.pop();
            tempQue.push(front);
        }
        int res = que.front();
        que = tempQue;
        return res;
    }
    
    /** Get the top element. */
    int top() {
        if (que.empty()) return -1;
        queue<int> tempQue;
        int que_size = que.size();
        int res = 0;
        for (int i = 0; i < que_size; i++)
        {
            res = que.front();
            que.pop();
            tempQue.push(res);
        }
        que = tempQue;
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }

private:
    queue<int> que;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

- `MyStack::Push(int x)` 方法，直接将元素加入队尾；
- `MyStack::pop()` 方法，借助一个临时的队列，记录原队列中前 n - 1 个元素，最后返回原队列的最后一个元素；
- `MyStack::top()` 方法，与 pop() 类似；
- `MyStack::empty()`方法，直接返回队列是否为空。
