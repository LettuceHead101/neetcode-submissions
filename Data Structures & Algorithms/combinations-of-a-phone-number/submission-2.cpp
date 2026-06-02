class Solution {
public:
    vector<string> result;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return result;

        backtrack(0, "", digits);

        return result;
    }

    void backtrack(int i, string current, string& digits) {
        if(current.size() == digits.size()) {
            result.push_back(current);
            return;
        }

        string chars = digitToChar[digits[i] - '0'];
        for(char c : chars) {
            backtrack(i + 1, current + c, digits);
        }
    }

};
