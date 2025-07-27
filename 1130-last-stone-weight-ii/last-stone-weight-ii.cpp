class Solution {
    int OFFSET = 3000;
    int dp[32][6004];
public:
    Solution(){
        memset(dp, -1, sizeof(dp));
    }
    int solve(vector<int> &nums, int n, int sum){
        if (n == nums.size()){
            if (sum < 0) return 5000;
            return sum;
        }
        
        if (dp[n][OFFSET+sum] != -1) return dp[n][OFFSET+sum];

        int add = solve(nums, n+1, sum + nums[n]);
        int sub = solve(nums, n+1, sum - nums[n]);

        dp[n][OFFSET+sum] = min(add, sub);
        
        return dp[n][OFFSET+sum];
    }
    int lastStoneWeightII(vector<int>& stones) {
        return solve(stones, 0, 0);
    }
};