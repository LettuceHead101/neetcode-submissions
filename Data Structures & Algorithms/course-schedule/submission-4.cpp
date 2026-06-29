class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjacency(numCourses);
        int processed = 0;
    
        for(auto& p : prerequisites){
            indegree[p[0]]++;
            adjacency[p[1]].push_back(p[0]);
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()) {
            int course = q.front();
            q.pop();
            processed++;

            for(auto dep : adjacency[course]){
                indegree[dep]--;

                if(indegree[dep] == 0){
                    q.push(dep);
                }
            }
        }

        return processed == numCourses;
    }
};
