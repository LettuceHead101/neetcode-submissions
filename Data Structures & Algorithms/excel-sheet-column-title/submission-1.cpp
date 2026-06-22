class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

        while(columnNumber > 0) {
            columnNumber--;
            result += alphabet[columnNumber % 26];
            columnNumber /= 26;
        }
        
        reverse(result.begin(), result.end());

        return result;
    }
};