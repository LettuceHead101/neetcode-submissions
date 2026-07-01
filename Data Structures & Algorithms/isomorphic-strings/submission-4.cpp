class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> m;
        unordered_set<char> mapped_t;

        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) != m.end()) {
                if (m[s[i]] != t[i]) {
                    return false;
                }
            } 

            else {
                if (mapped_t.find(t[i]) != mapped_t.end()) {
                    return false; 
                }
                
                m[s[i]] = t[i];
                mapped_t.insert(t[i]);
            }
        }

        return true;
    }
};