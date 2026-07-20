class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unique_ptr<unordered_map<char, int>> m = make_unique<unordered_map<char, int>>();

        for(int i = 0; i < s.size(); i++){
            (*m)[s[i]]++;
            (*m)[t[i]]--;
        }

        for(auto& [k,v] : *m){
            if(v != 0) return false;
        }

        return true;
    }
};
