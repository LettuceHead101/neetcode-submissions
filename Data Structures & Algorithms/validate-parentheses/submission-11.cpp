class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mappings{{')', '('}, {']', '['}, {'}', '{'}};

        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                if(stk.empty()) return false;

                if(mappings[c] != stk.top()) {
                    return false;
                }
                stk.pop();
            }
        }
        
        return stk.empty();
    }
};
