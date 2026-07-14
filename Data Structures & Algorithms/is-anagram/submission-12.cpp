class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<int, int> seen;
        for(int i = 0; i < s.size(); i++){
            seen[s[i]]++;
            seen[t[i]]--;
        }

        for(auto& [_,v] : seen){
            if(v != 0) return false;
        }
        return true;
    }
};
