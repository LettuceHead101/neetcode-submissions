class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for(const string& s : strs){
            string key = "";
            vector<int> freq(26, 0);

            for(const char& c : s){
                freq[c - 'a']++;
            }

            for(int i = 0; i < 26; ++i){
                key += to_string(freq[i]) + "#";
            }

            groups[key].push_back(s);
        }

        vector<vector<string>> result;

        for(auto [key, value] : groups) {
            result.push_back(value);
        }

        return result;
    }
};
