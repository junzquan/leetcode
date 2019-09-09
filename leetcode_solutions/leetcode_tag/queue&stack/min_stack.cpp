#include <iostream>
#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (s.empty() || min.top() >= x)
            min.push(x);
        s.push(x);
    }
    
    void pop() {
        if (s.top() == min.top())
            min.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
    
private:
    std::stack<int> s;
    std::stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main() {
    MinStack s;
    s.push(0);
    s.push(1);
    s.push(0);
    s.getMin();
    s.pop();
    s.getMin();
    
    return 0;
}
