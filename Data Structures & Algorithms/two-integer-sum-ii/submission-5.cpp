class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        sort(numbers.begin(), numbers.end());

        int l = 0;
        int r = numbers.size() - 1;

        while(l < r){
            if(numbers[l] + numbers[r] == target){
                return {l+1,r+1};
            } else if(numbers[l] + numbers[r] > target){
                r--;
            } else{
                l++;
            }
        }
        return {-1, -1};
    }
};
