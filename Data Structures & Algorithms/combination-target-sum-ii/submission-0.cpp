class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        dfs(candidates, target, current, 0, 0);

        return result;
    }

    void dfs(vector<int>& candidates, int target, vector<int>& current, int i, int total) {
        if(total == target) {
            result.push_back(current);
            return;
        }

        if(total > target || i == candidates.size()) {
            return;
        }

        current.push_back(candidates[i]);
        dfs(candidates, target, current, i+1, total + candidates[i]);
        current.pop_back();


        while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        
        dfs(candidates, target, current, i+1, total);        
    }
};
