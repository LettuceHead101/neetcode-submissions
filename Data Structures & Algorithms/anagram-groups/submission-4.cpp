class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;

        for(string s : strs) {
            string temp = "";
            vector<int> temparray(26, 0);

            for(char c : s) {
                temparray[c - 'a']++;
            }

            for(int x : temparray) {
                temp += x + 'a';
            }

            hashmap[temp].push_back(s);
        }

        vector<vector<string>> result;

        for(auto it : hashmap) {
            result.push_back(it.second);
        }
        return result;
    }
};
