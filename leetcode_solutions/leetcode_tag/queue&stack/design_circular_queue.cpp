class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : front(0), rear(0), reset(true) {
        que.resize(k);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        que[rear] = value;
        if (front == rear && reset) reset = false;
        rear = (rear + 1) % que.size();
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty())
            return false;
        else {
            front = (front + 1) % que.size();
            if (front == rear && !reset) reset = true;
            return true;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty())
            return -1;
        else
            return que[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty())
            return -1;
        else {
            if (rear == 0)
                return que[que.size() - 1];
            return que[rear - 1];
        }
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if (front == rear && reset)
            return true;
        else
            return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (front == rear && !reset)
            return true;
        else
            return false;
    }
    
private:
    std::vector<int> que;
    int front, rear;
    bool reset;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */

