class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(0, 0, result, "", n);
        return result;
    }

    void backtrack(int openN, int closedN, vector<string>& result, string curr, int n){
        if(openN == closedN && closedN == n){
            result.push_back(curr);
            return;
        }

        if(openN < n){
            curr.push_back('(');
            backtrack(openN+1, closedN, result, curr, n);
            curr.pop_back();
        }

        if(closedN < openN){
            curr.push_back(')');
            backtrack(openN, closedN+1, result, curr, n);
            curr.pop_back();
        }
    }
};
