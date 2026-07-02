class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i-1])continue;
            int  curr = nums[i];
            int l = i+1;
            int r = nums.size()-1;

            while(l < r){

                if(nums[l] + nums[r] == (curr * -1)){
                    v.push_back({curr, nums[l], nums[r]});
                    l++;
                    r--;

                    while( l < r && nums[l] == nums[l-1]){
                         l++;
                        
                    }
                    while(r > l && nums[r] == nums[r+1]){
                        r--;
                       
                    }
              
                }else{
                    if((nums[l] + nums[r] > (curr * -1))){
                        r--;
                    }else{
                        l++;
                    }

                }
            }

        }
        return v;
    }
};
