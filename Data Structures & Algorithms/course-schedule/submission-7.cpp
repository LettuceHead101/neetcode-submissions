class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjacency(numCourses);
        queue<int> q;
        int processedCourses = 0;

        for(auto& p : prerequisites){
            indegree[p[0]]++;
            adjacency[p[1]].push_back(p[0]);
        }

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int course = q.front();
            q.pop();
            processedCourses++;

            for(auto& p : adjacency[course]){
                indegree[p]--;
                if(indegree[p] == 0){
                    q.push(p);
                }
            }
        }

        return processedCourses == numCourses;
    }
};
