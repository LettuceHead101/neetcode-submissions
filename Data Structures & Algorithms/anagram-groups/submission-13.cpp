class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(string s : strs) {
            vector<int> freq(26, 0);
            for(char c : s) {
                freq[c - 'a']++;
            }

            string key = "";
            for(int i = 0; i < 26; i++) {
                key += freq[i];
            }
            m[key].push_back(s);
        }
        vector<vector<string>> result;

        for(auto [k,v] : m) {
            result.push_back(v);
        }

        return result;
    }
};
