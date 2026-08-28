class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (const string& token : tokens) {
            if (token == "+") {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                stk.push(a + b);
            } else if (token == "-") {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                stk.push(a - b);
            } else if (token == "*") {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                stk.push(a * b);
            } else if (token == "/") {
                // Integer division in C++ truncates toward zero by default
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                stk.push(a / b);
            } else {
                // Token is a number, push it onto the stack
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};
