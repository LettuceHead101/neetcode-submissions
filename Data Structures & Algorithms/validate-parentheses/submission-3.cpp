class Solution {
public:
    bool isValid(string s) {
        stack<char> order; 

        for(char c : s) {
            if(c == '{') {
                order.push('}');
            } else if (c == '[') {
                order.push(']');
            } else if (c == '(') {
                order.push(')');
            } else {
                if(order.empty()) return false;

                char orderTop = order.top();
                order.pop();
                if(orderTop != c) {
                    return false;
                }
            }
        }

        return (order.empty()) ? true : false;
    }
};
