class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vs(26,0);
        vector<int> vt(26,0);
        
        for(const auto& c : s){
            vs[c - 'a']++;
        }

        for(const auto& c : t){
            vt[c - 'a']++;
        }
        return vs == vt;
    }
};
