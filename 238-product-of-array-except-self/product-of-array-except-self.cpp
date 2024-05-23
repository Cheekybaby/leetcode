class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(), 1);
        vector<int> suff(nums.size(), 1);

        for (int i=1; i<nums.size(); i+=1){
            pre[i] = pre[i-1] * nums[i-1];
        }
        for (int j=nums.size()-2; j>=0; j-=1){
            suff[j] = suff[j+1] * nums[j+1];
        }

        vector<int> ans;
        for (int i=0; i<nums.size(); i+=1){
            ans.push_back(pre[i]*suff[i]);
        }

        return ans;
    }
};