class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sets; 
        
        for(string s : strs) {
            string serializedString = "";
            vector<int> frequencyCount(26, 0);

            for(char c : s) {
                int n = c - 'a';
                frequencyCount[n]++;
            }

            for(int i = 0; i < 26; i++) {
                serializedString += to_string(frequencyCount[i]) + 'a';
            }

            sets[serializedString].push_back(s);
        }

        vector<vector<string>> solution;
        for(auto p : sets) {
            solution.push_back(p.second);
        }

        return solution;
    }
};
