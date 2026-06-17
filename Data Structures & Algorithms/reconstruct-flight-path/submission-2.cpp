class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;
        stack<string> stk;
        unordered_map<string, vector<string>> adjacency;

        for(auto ticket : tickets) {
            adjacency[ticket[0]].push_back(ticket[1]);
        }

        for(auto& [k,v] : adjacency) {
            sort(v.rbegin(), v.rend());
        }

        stk.push("JFK");

        while(!stk.empty()) {
            string key = stk.top();
            
            if(adjacency[key].size() > 0) {
                string value = adjacency[key].back();
                adjacency[key].pop_back();
                stk.push(value);
            } else {
                result.push_back(key);
                stk.pop();
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
