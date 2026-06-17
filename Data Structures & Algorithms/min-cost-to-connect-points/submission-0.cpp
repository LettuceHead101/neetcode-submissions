class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //working dist, node
        vector<int> visited(points.size(),0);
        int ans = 0;
        int visited_count = 0;


        pq.push({0,0});

        while(!pq.empty()){
            auto [dist, node] = pq.top();
            pq.pop();
            if(visited[node]++ > 0)continue;
            visited_count++;
            int x = points[node][0];
            int y = points[node][1];
            ans += dist;
            for(int i = 0 ; i < points.size(); ++i){
                if(visited[i] > 0)continue;
                
                int manhattan = abs(points[i][0] - x ) + abs(points[i][1] - y);
                pq.push({ manhattan, i});
            }
            
        }



        return ans;
    }
};
