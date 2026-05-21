class Solution {
public:
    bool isValid(string s) {
        stack<char> tower;
        for(int i = 0; i < s.size(); i++) {

            // if we're not pushing then pop and check
            if(s[i] != '(' && s[i] != '[' && s[i] != '{') {
                if(tower.empty()) return false;
                
                if(s[i] == ')'){
                    if(tower.top() != s[i]) return false;
                    tower.pop();
                }
                if(s[i] == ']') {
                    if(tower.top() != s[i]) return false;
                    tower.pop();
                }
                if(s[i] == '}') {
                    if(tower.top() != s[i]) return false;
                    tower.pop();
                }
            }

            if(s[i] == '('){
                tower.push(')');
            }
            if(s[i] == '[') {
                tower.push(']');
            }
            if(s[i] == '{') {
                tower.push('}');
            }
        }


        return (tower.empty()) ? true: false;
    }
};
