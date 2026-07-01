class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // if(strs.size() == 1)return strs[0];
        string ans = "";

        int smallest = INT_MAX;
        for(auto word : strs){
            smallest = min((int)word.size(), smallest);
        }

        for(int i = 0; i < smallest; ++i){
            vector<bool> v(smallest, true);
            char curr = strs[0][i];
            for(auto w : strs){
                if(!v[i])break;

                v[i] = (w[i] == curr);
            }
            if(v[i])ans += curr;
            if(!v[i])break;
        }
        return ans;
    }
};