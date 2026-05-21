class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;

        for(string s : strs) {
            vector<int> fCount(26, 0);
            for(char c : s) {
                fCount[c-'a']++;
            }
            string hashstring = "";
            for(int i = 0; i < 26; i++) {
                hashstring += to_string(fCount[i]) + ';';
            }

            hashMap[hashstring].push_back(s);
        }
        vector<vector<string>> solution;
        for(auto it : hashMap) {
            solution.push_back(it.second);
        }

        return solution;
    }
};
