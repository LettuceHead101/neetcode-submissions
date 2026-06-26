class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;

        dfs(candidates, curr, target, 0);

        return result;
    }

    void dfs(vector<int>& candidates, vector<int> curr, int target, int i) {
        if(target == 0) {
            result.push_back(curr);
            return;
        }

        if(target < 0 || i >= candidates.size()) {
            return;
        }

        curr.push_back(candidates[i]);
        dfs(candidates, curr, target-candidates[i], i+1);
        curr.pop_back();

        while(i+1 < candidates.size() && candidates[i] == candidates[i + 1] ) {
            i++;
        }

        dfs(candidates, curr, target, i+1);
    }
};
