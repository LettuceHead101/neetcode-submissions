class MinStack {
public:
    vector<vector<int>> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()) {
            stk.push_back({val, val});
        } else {
            int minMin = stk.back()[1];
            minMin = min(val, minMin);
            stk.push_back({val, minMin});
        }
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        return stk.back()[0];
    }
    
    int getMin() {
        return stk.back()[1];
    }
};
