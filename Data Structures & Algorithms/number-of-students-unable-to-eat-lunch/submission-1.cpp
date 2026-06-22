class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int,int> m;
        int ans = 0;

        for(auto student : students){
            m[student]++;
        }
        int r = 0;
        for( r = 0; r < sandwiches.size(); ++r){
            if(m[sandwiches[r]] > 0){
                m[sandwiches[r]]--;
                continue;
            }
            break;
        }

        ans += m[0];
        ans += m[1];
        return ans;
    }
};