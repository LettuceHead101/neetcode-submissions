class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n =  temperatures.size();
        vector<int> days(n, 0);

        for(int i = 0; i < n; i++) {
            int counter = 0;
            bool day = false;
            for(int j = i+1; j < n; j++) {
                counter++;
                if(temperatures[j] > temperatures[i]) {
                    day = true;
                    break;
                }
            }
            
            days[i] = (day) ? counter : 0;
        }

        return days;
    }
};
