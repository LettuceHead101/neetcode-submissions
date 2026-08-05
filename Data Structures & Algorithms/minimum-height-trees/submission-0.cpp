class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> result;
        // map nodes to their heights
        unordered_map<int, int> nodeAndHeight;

        for(int i = 0; i < n; i++){
            int h = returnTreeHeight(i, edges);
            nodeAndHeight[i] = h;

            // if we have empty place in regardless
            if(result.empty()){
                result.push_back(i);
            } else {
                // if it isn't empty
                // check if our value is equal than what's in there
                if(h == nodeAndHeight[result.back()]){
                    result.push_back(i);
                } else if(h < nodeAndHeight[result.back()]){

                    // if our value is less
                    // remove everything and insert our node
                    while(!result.empty()){
                        result.pop_back();
                    }

                    result.push_back(i);
                }
            }
        }

        return result;
    }

    // construct the tree then return the height
    int returnTreeHeight(int root, vector<vector<int>>& edges) {
        // A valid tree with n nodes always has n - 1 edges
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(root);
        visited[root] = true;
        int height = 0;

        // Level-order traversal to measure tree height
        while (!q.empty()) {
            int sz = q.size();
            height++;
            for (int i = 0; i < sz; i++) {
                int curr = q.front();
                q.pop();
                for (int neighbor : adj[curr]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }

        return height;
    }
};