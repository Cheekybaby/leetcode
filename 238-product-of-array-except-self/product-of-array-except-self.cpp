class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int product = 1;
        for(int i=0; i<nums.size()-1; i+=1){
            product = nums[i]*product;
            ans[i+1] = product;
        }
        product = 1;
        for (int i=nums.size()-1; i>0; i-=1){
            product = nums[i] * product;
            ans[i-1] *= product;
        }

        return ans;
    }
};