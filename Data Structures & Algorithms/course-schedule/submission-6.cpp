class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int processed = 0;

        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjacency(numCourses);

        for(auto& pre : prerequisites){
            indegree[pre[0]]++;
            adjacency[pre[1]].push_back(pre[0]);
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int course = q.front();
            processed++;
            q.pop();

            for(auto& item : adjacency[course]){
                indegree[item]--;
                if(indegree[item] == 0){
                    q.push(item);
                }
            }
        }

        return processed == numCourses;
    }
};
