class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for(const string& s : strs) {
            vector<int> freq(26, 0);
            string serial = "";
            for(const char& c : s) {
                freq[c - 'a']++;
            }
            for(int i = 0; i < 26; ++i) {
                serial += "#" + to_string(freq[i]);
            }
            groups[serial].push_back(s);
        }

        vector<vector<string>> result;
        for(auto [key, val] : groups) {
            result.push_back(val);
        }

        return result;
    }
};
