class Solution {
public:
    bool isPalindrome(string s) {
        // 1. Process string
        string processed = "";
        for(char c : s) {
            if(isalnum(c)) {
                processed += tolower(c);
            }
        }

        // 2. Set pointers based on the NEW processed string
        int start = 0;
        int end = processed.size() - 1;

        // 3. Compare and move pointers inward
        while(start < end) { // 'start < end' is slightly better than '<=' here
            if(processed[start] != processed[end]){
                return false;
            }
            start++; // Move left pointer right
            end--;   // Move right pointer left
        }
        return true;
    }
};