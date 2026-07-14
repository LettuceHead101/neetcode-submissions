class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for(string& s : strs){
            string key = "";
            vector<int> freq(26, 0);

            for(char c : s){
                freq[c- 'a']++;
            }

            for(int i = 0; i < 26; i++){
                key += freq[i] + 'a';
            }

            groups[key].push_back(s);
        }

        vector<vector<string>> result;

        for(auto& [k,v] : groups){
            result.push_back(v);
        }

        return result;
    }
};
