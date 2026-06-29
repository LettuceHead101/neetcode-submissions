class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int processed = 0;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjacency(numCourses);

        for(auto& pre : prerequisites) {
            indegree[pre[0]]++;
            adjacency[pre[1]].push_back(pre[0]);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int x = q.front();
            q.pop();
            processed++;
            for(auto course : adjacency[x]){
                indegree[course]--;
                if(indegree[course] == 0) {
                    q.push(course);
                }
            }
        }

        return numCourses == processed;
    }
};
