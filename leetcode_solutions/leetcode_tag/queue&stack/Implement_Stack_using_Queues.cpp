class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (_q.empty())
        {
            _q.push(x);
            return;
        }
        vector<int> temp_v;
		int size = _q.size();
        for (int i = 0; i != size; i++)
        {
            int data = _q.front();
            _q.pop();
            temp_v.push_back(data);
        }
        _q.push(x);
        for (auto i : temp_v)
			_q.push(i);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int data = _q.front();
        _q.pop();
        return data;
    }
    
    /** Get the top element. */
    int top() {
        return _q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return _q.empty();
    }
    
private:
    queue<int> _q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */