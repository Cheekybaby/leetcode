class NumArray {
public:
    vector<int> prefixsum;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int i=0; i<nums.size(); i+=1){
            sum+=nums[i];
            prefixsum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int ans = prefixsum[right];
        if (left>=1){
            ans-=prefixsum[left-1];
        }

        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */