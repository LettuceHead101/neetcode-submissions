class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // hold strings based on frequencies of characters in this map
        unordered_map<string, vector<string>> lists;

        // iterate through all the strings
        for(string s : strs) {
            vector<int> frequencyArray(26, 0);

            // grab the frequncies of our current string
            for(char c : s) {
                frequencyArray[c-'a']++;
            } 

            // now transform that array into a safe hash string
            string hashstring = "";
            for(int i = 0; i < 26; i++) {
                hashstring += to_string(frequencyArray[i]) + '#';
            }

            
            lists[hashstring].push_back(s);
        }
        vector<vector<string>> solution;

        for(auto pair : lists) {
            solution.push_back(pair.second);
        }
        
        return solution;
    }
};
