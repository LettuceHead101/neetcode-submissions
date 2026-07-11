class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());
        dfs(result, curr, candidates, target, 0);

        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int> curr, vector<int>& candidates, int target, int i){
        if (target == 0){
            result.push_back(curr);
            return;
        }

        if(target < 0 || i >= candidates.size()){
            return;
        }

        curr.push_back(candidates[i]);
        dfs(result, curr, candidates, target-candidates[i], i+1);

        curr.pop_back();
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]){
            i++;
        }

        dfs(result, curr, candidates, target, i+1);
    }
};
