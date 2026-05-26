class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;

        for(string s : strs) {
            vector<char> freqCount(26, 0);

            for(char c : s) {
                freqCount[c - 'a']++;
            }

            string serialized = "";

            for(int i = 0; i < 26; i++) {
                serialized += freqCount[i];
            }

            hashmap[serialized].push_back(s);
        }

        vector<vector<string>> result;

        for(auto it : hashmap) {
            result.push_back(it.second);
        }

        return result;
    }
};
