class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;    

        for(string s : strs) {

            vector<char> freq(26, 0);
            for(char c : s) {
                freq[c - 'a']++;
            }

            string ser = "";

            for(int i = 0; i < 26; i++) {
                ser += freq[i];
            }

            m[ser].push_back(s);
        }

        vector<vector<string>> result;

        for(auto it : m) {
            result.push_back(it.second);
        }

        return result;
    }
};
