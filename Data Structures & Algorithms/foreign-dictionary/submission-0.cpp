class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        string ans = "";
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        int size = words.size();
        queue<char> q;

        for(const auto& word : words){
            for(const auto& w : word){
                indegree[w] = 0;
            }
        }

        for(int i = 0; i < size -1; ++i){
            string curr = words[i];
            string after_curr = words[i+1];
            int min_len = min(curr.size(), after_curr.size());
            if(curr.substr(0, min_len) == after_curr.substr(0, min_len) && curr.size() > after_curr.size()){
                return "";
            }

            auto [curr_it , after_curr_it] = mismatch(curr.begin(), curr.end(), after_curr.begin(), after_curr.end());

            if(curr_it == curr.end() || after_curr_it == after_curr.end()){
                continue;
            }
            if(!adj[*curr_it].count(*after_curr_it)){// if we inserted before just ignore the repeats
                indegree[*after_curr_it]++;
                adj[*curr_it].insert(*after_curr_it);
            }
        }



        for(const auto& [k,v]: indegree){
            if(v == 0){
                q.push(k);
            }
        }

        while(!q.empty()){
            char curr = q.front();
            q.pop();
            ans += curr;
            for(const auto& c : adj[curr]){
                indegree[c]--;
                if(indegree[c] == 0){
                    q.push(c);
                }

            }
        }

        return (ans.size() == indegree.size())? ans : "" ;





        
    }
};
