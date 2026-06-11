class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int, int>> s;

        vector<pair<int, int>> pas;

        for(int i = 0; i < position.size(); i++) {
            pas.push_back({position[i], speed[i]});
        }

        sort(pas.begin(), pas.end());

        while(!pas.empty()) {
            pair<int, int> pback;
            pback = pas.back();
            pas.pop_back();

            if(s.empty()) {
                s.push(pback);
                continue;
            }

            pair<int, int> sTop;
            sTop = s.top();
            s.pop();

            double pbt = (double)(target - pback.first) / pback.second;
            double stt = (double)(target - sTop.first) / sTop.second;

            if(pbt <= stt) {
                s.push(sTop);
            } else {
                s.push(sTop);
                s.push(pback);
            }
        }

        return s.size();
    }
};
