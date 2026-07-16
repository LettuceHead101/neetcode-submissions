class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 1) return s.substr(0,1);
        string t = "@#";
        for(char c : s){
            t += c;
            t += "#";
        }
        t += "!";

        int working_R = 0;
        int working_C = 0;
        int C = 0;
        int R = 0;
        int length = 0;
        int start_idx = -1;
        vector<int> dp(t.size(), 1);

        for(int i = 1; i < t.size() - 1; i++){
            // check for shortcut
            if(i < working_R && dp[working_C*2 - i] > 1){
                dp[i] = min(working_R - i, dp[working_C*2 - i]);
            }

            // advance the pallindrome
            while(t[i + dp[i]] == t[i - dp[i]]){
                dp[i]++;
            }

            // adjust longest
            if(i + dp[i] > working_R){
                working_R = dp[i] + i;
                working_C = i;
            }

            if(dp[i] > length){
                C = i;
                R = dp[i] + i;
                length = dp[i];
            }
        }

        start_idx = (C - length)/2;
        return s.substr(start_idx , length - 1);
    }
};
