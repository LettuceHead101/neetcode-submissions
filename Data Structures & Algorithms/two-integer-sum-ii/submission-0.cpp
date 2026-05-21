class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> snail;

        for(int i = 0; i < numbers.size(); i++) {
            int difference = target - numbers[i];
            if(snail.find(difference) != snail.end()) {
                return{snail[difference],i+1};
            }
            snail.insert({numbers[i], i + 1});
        }

        return {-1, -1};
    }
};
