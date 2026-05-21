class MinStack {
public:
    vector<pair<int, int>> minstack;
    MinStack() {
        
    }
    
    void push(int val) {
        if(minstack.empty()) {
            minstack.push_back({val, val});
        } else {
            if(minstack.back().second > val) {
                minstack.push_back({val, val});
            } else {
                minstack.push_back({val, minstack.back().second});
            }
        }
    }
    
    void pop() {
        minstack.pop_back();
    }
    
    int top() {
        return minstack.back().first;
    }
    
    int getMin() {
        return minstack.back().second;
    }
};
