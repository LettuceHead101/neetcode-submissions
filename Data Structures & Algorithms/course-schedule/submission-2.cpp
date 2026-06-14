class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> adjacency;
        queue<int> q;
        int result = 0;

        for(int i = 0; i < numCourses; i++) {
            indegree[i] = 0;
        }

        for(auto it : prerequisites) {
            indegree[it[0]]++;
            adjacency[it[1]].push_back(it[0]);
        }

        for(auto [k,v] : indegree) {
            if(v == 0) q.push(k);
        }

        while(!q.empty()) {
            if(result > numCourses) return false;
            int temp = q.front();
            q.pop();


            for(auto it : adjacency[temp]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }

            result++;            
        }

        return result == numCourses;
    }
};
