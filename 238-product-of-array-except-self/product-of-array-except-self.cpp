class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 1);
        for(int i=1; i<nums.size(); i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        int product = nums[nums.size()-1];
        for(int i=nums.size()-2; i>=0; i--){
            prefix[i] *= product;
            product *= nums[i];
        }
        return prefix;
    }
};