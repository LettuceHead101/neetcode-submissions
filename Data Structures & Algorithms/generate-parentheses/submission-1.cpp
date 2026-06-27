class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> result;
        backtrack(0, 0, s, result, n);

        return result;
    }

    void backtrack(int openN, int closedN, string& s, vector<string>& result, int& n) {
        if(openN == closedN && closedN == n) {
            result.push_back(s);
            return;
        }

        if(openN < n) {
            s.push_back('(');
            backtrack(openN+1, closedN, s, result, n);
            s.pop_back();
        }

        if(closedN < openN) {
            s.push_back(')');
            backtrack(openN, closedN+1, s, result, n);
            s.pop_back();
        }
    }
};
