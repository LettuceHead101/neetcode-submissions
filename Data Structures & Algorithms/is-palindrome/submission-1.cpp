class Solution {
public:
    bool isPalindrome(string s) {
        string processed = "";
        for(char c : s) {
            if(isalnum(c)) {
                processed += tolower(c);
            }
        }

        int start = 0;
        int end = processed.size() - 1;

        while(start < end) {
            if(processed[start] != processed[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};