class Solution {
private:
    int OFFSET = 1000;
    int dp[22][2004];
public:
    Solution(){
        memset(dp, -1, sizeof(dp));
    }
    int solve(vector<int> &nums, int target, int n, int sum){
        if (n < 0){
            if (sum == target) return 1;
            return 0;
        }
        
        if (dp[n][OFFSET+sum] != -1) return dp[n][OFFSET+sum];

        int add = solve(nums, target, n-1, sum + nums[n]);
        int sub = solve(nums, target, n-1, sum - nums[n]);

        dp[n][OFFSET+sum] = add + sub;
        
        return dp[n][OFFSET+sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size()-1;
        int cnt = solve(nums, target, n, sum);
        return cnt;
    }
};