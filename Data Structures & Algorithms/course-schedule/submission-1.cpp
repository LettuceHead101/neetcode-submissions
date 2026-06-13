class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> adjacencyList;
        int result = 0;

        for(int i = 0; i < numCourses; i++) {
            indegree[i] = 0;
        }

        for(auto prereq : prerequisites) {
            indegree[prereq[0]]++;
            adjacencyList[prereq[1]].push_back(prereq[0]);
        }

        queue<int> q;

        for(auto [k,v] : indegree) {
            if(v == 0) q.push(k);
        }

        while(!q.empty()) {
            if(result > numCourses) return false;
            result++;

            int temp = q.front();
            q.pop();

            auto item = adjacencyList[temp];

            for(auto it : item){
                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return result == numCourses;
    }
};
