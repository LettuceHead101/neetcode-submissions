class Solution {
public:
    vector<int> indegree;
    vector<vector<int>> adj;
    vector<int> output;


    void dfs(int node){
        output.push_back(node);
        indegree[node]--;
        for(int nei : adj[node]){
            indegree[nei]--;
            if(indegree[nei] == 0) {
                dfs(nei);
            }
        }
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        indegree = vector<int>(numCourses, 0);
        adj = vector<vector<int>>(numCourses);

        for(auto& pre : prerequisites){
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                dfs(i);
            }
        }

        if(output.size() != numCourses) return {};
        return output;
    }
};