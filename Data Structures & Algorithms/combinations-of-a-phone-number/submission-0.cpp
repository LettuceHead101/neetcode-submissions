class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Edge case: empty input
        if (digits.empty()) {
            return {};
        }
        
        const vector<string> phone_map = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> answer;
        answer.push_back(""); // start with an empty string to build upon
        
        // iterate through each digit in the input string
        for (char digit : digits) {
            vector<string> new_combinations;
            string letters = phone_map[digit - '0'];
            
            // for every combination we've built so far...
            for (const string& combo : answer) {
                // append every new possible letter
                for (char letter : letters) {
                    new_combinations.push_back(combo + letter);
                }
            }
            
            // replace the old combinations with the new, longer ones
            answer = new_combinations;
        }
        
        return answer;
    }
};