class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0; 
        int maxValue = 0;
        unordered_set<char> seen;
        for(int i = 0; i < n; i++) {
            if(seen.find(s[i]) != seen.end()) {
                while(seen.find(s[i]) != seen.end()) {
                    seen.erase(s[left]);
                    left++;
                }
                seen.insert(s[i]);
            } else {
                seen.insert(s[i]);
                if(i - left + 1 > maxValue) {
                    maxValue = i - left + 1;
                }
            }
        }
        return maxValue;
    }
};