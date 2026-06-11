class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<char> count(26, 0);
        for(int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for(int x : count) {
            if(x != 0) return false;
        }
        return true;
    }
};
