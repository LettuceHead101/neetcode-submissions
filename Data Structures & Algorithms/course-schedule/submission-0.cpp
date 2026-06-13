class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> adjacency;
        int result = 0;

        for(int i = 0; i < numCourses; i++) {
            indegree[i] = 0;
        }

        for(vector<int> p : prerequisites) {
            indegree[p[0]]++;
            adjacency[p[1]].push_back(p[0]);
        }

        queue<int> q;

        for(auto [k,v] : indegree) {
            if(v <= 0) {
                q.push(k);
            }
        }

        while(!q.empty()) {
            if(result > numCourses) return false;

            int temp = q.front();
            q.pop();

            for(int i = 0; i < adjacency[temp].size(); i++) {
                indegree[adjacency[temp][i]]--;
                if(indegree[adjacency[temp][i]] == 0) {
                    q.push(adjacency[temp][i]);
                }
            }

            result++;
        }

        return (result == numCourses);
    }
};
