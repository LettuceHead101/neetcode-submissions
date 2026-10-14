class MinStack {
public:
    vector<pair<int, int>> stk;

    MinStack() {}
    
    void push(int val) {
        if(stk.empty()){
            stk.push_back({val, val});
            return;
        } else {
            int small = val;
            if(stk.back().second < val) {
                small = stk.back().second;
            }

            stk.push_back({val, small});
        }
    }
    
    void pop() {
       stk.pop_back(); 
    }
    
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return stk.back().second;
    }
};
