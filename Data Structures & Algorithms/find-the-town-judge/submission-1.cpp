class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adjacency(n+1);
        vector<int> outdegree(n+1, 0);
        int judge = -1;
        queue<int> q;

        for(auto& v : trust){
            outdegree[v[0]]++;
            adjacency[v[1]].push_back(v[0]);
        }


        for(int i = 1; i <= n; i++){
            if(outdegree[i] == 0){
                q.push(i);
            }
        }

        if(q.empty()) return -1;

        int potential = q.front();
        q.pop();

        if(adjacency[potential].size() == n-1){
            return potential;
        } else{
            return -1;
        }


        return judge;
    }
};