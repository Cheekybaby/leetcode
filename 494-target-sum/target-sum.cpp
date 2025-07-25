class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int max_sum = accumulate(nums.begin(), nums.end(), 0);
        int min_sum = -1 * max_sum;

        vector<vector<int>> dp(n, vector<int> ((2*max_sum)+1, 0));
        dp[0][nums[0] + max_sum] = 1;
        dp[0][-nums[0] + max_sum] += 1;

        for(int i=1; i<n; i++){
            for(int j=min_sum; j<=max_sum; j++){
                if (dp[i-1][j+max_sum] > 0){
                    dp[i][j+nums[i]+max_sum] += dp[i-1][j+max_sum];
                    dp[i][j-nums[i]+max_sum] += dp[i-1][j+max_sum];
                }
            }
        }

        return abs(target) > max_sum ? 0 : dp[n-1][target+max_sum];
    }
};