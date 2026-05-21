class NumArray {
public:
    vector<int> numlist;
    NumArray(vector<int>& nums) {
        numlist = nums;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        while(left <= right) {
            if(left == right) {
                sum += numlist[left];
                left++;
            } else {
                sum += numlist[left] + numlist[right];
                left++;
                right--;
            }
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */