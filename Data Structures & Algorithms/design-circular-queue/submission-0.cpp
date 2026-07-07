class MyCircularQueue {
private:
    vector<int> q;
    int head;       // Points to the front of the queue
    int count;      // Current number of elements in the queue
    int capacity;   // Maximum size of the queue

public:
    MyCircularQueue(int k) {
        q.resize(k);
        head = 0;
        count = 0;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        
        // Calculate where the back of the queue is right now
        int tail = (head + count) % capacity;
        q[tail] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        
        // Move the head forward by 1, wrapping around if necessary
        head = (head + 1) % capacity;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        
        // Calculate the position of the last inserted element
        int tail = (head + count - 1) % capacity;
        return q[tail];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};