class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

         vector<vector<string>> ans;
         unordered_map<int, vector<string>> m;

         for(const auto& word : strs){
            int hash = helper(word);
            m[hash].push_back(word);
         }

         for(auto [k,v] : m){
            ans.push_back(v);
         }
        return ans;
    }

    size_t helper(string s){

        vector<int> v(26,0);
        int h = 0;
        
        for(const auto& c : s){
            v[c - 'a']++;
        }

        for(int i = 0; i < v.size(); ++i){
            h ^= hash<int>{}(v[i])+( (h << 6) + (h >> 2) );
        }
        return h;
    }
};
