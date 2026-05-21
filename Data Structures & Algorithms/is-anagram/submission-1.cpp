class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m) return false;

        unordered_map<char, int> css;
        unordered_map<char, int> cst;

        for(int i = 0; i < n; i++) {
            // check if it exists
            if(css.find(s[i]) != css.end()) {
                css[s[i]]++;
            } else {
                css.insert({s[i], 1});                
            }
            if(cst.find(t[i]) != cst.end()) {
                cst[t[i]]++;
            } else {
                cst.insert({t[i], 1});                    
            }
        }

        return (css == cst) ? true : false;
    }
};
