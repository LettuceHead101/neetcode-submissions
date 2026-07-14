class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int result = 0;
        unordered_set<char> seen;

        for(int r = 0; r < s.size(); r++){
            char c = s[r];

            while(seen.count(c)){
                seen.erase(s[l]);
                l++;
            }

            seen.insert(c);

            result = max(result, (r-l)+1);

        }
        return result;
    }
};
