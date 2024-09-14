class Solution {
public:
    int solve(vector<int> &nums, int index, vector<int> &memo){
        if (index == 0){
            return 1;
        }
        if (memo[index] != -1){
            return memo[index];
        }

        int maxi = 1;
        for (int i=0; i<index; i+=1){
            if (nums[i] < nums[index]){
                maxi = max(maxi, 1 + solve(nums, i, memo));
            }
        }

        return memo[index] = maxi;
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        vector<int> dp(nums.size()+1, -1);
        for (int i=1; i<nums.size(); i+=1){
            ans = max(ans, solve(nums, i, dp));
        }

        return ans;
    }
};