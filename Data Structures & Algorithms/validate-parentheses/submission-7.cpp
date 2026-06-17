class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(char c : s) {
            if(c == '{') {
                stk.push('}');
            } else if (c == '(') {
                stk.push(')');
            } else if (c == '[') {
                stk.push(']');
            } else {
                if(stk.empty()) return false;

                char temp = stk.top();
                stk.pop();
                if(temp != c) {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
