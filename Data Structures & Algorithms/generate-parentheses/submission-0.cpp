class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        backtrack(0, 0, n, result, s);
        return result;
    }

    void backtrack(int openN, int closedN, int n, vector<string>& result, string& s) {
        if(openN == closedN && closedN == n) {
            result.push_back(s);
            return;
        }

        if(openN < n) {
            s += '(';
            backtrack(openN+1, closedN, n, result, s);
            s.pop_back();
        }
        if(closedN < openN) {
            s += ')';
            backtrack(openN, closedN+1, n, result, s);
            s.pop_back();
        }
    }
};
