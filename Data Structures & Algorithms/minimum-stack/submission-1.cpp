class MinStack {
public:
    vector<pair<int, int>> minStack;
    MinStack() {

    }
    
    void push(int val) {
        if(minStack.empty()) {
            minStack.push_back({val, val});
        } else {
            int current_min = minStack.back().second;
            minStack.push_back({val, min(val, current_min)});
        }
    }
    
    void pop() {
        minStack.pop_back();
    }
    
    int top() {
        return minStack.back().first;
    }
    
    int getMin() {
        return minStack.back().second;
    }
};
