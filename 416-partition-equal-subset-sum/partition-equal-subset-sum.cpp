class Solution {
public:
    bool sub(vector<int>&nums,int target,int ind,vector<vector<int>>&dp){
        if(target==0) return true;
        if(ind==0) return (nums[0]==target);
        if(dp[target][ind]!=-1) return dp[target][ind];
        bool notTake=sub(nums,target,ind-1,dp);
        bool Take=false;
        if(target>=nums[ind]) Take=sub(nums,target-nums[ind],ind-1,dp);
        return dp[target][ind]=(notTake|| Take);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;

        for(auto it:nums) totalSum+=it;
        if(totalSum%2) return false;
        int target=totalSum/2;
        vector<vector<int>>dp(target+1,vector<int>(n+1,-1));
        if(sub(nums,target,n-1,dp)) return true;
        return false;

         
    }
};
 