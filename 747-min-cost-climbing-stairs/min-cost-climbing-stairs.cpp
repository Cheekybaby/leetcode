class Solution {
public:
    int solve(vector<int> &cost, int n, vector<int> &dp){
        if (n < 0){
            return 0;
        }
        if (dp[n] != -1) return dp[n];

        int left = cost[n] + solve(cost, n-1,dp);
        int right = cost[n] + solve(cost, n-2, dp);

        return dp[n] = min(left, right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size()-1;
        vector<int> dp(n+1, -1);
        int ans = min(solve(cost, n, dp), solve(cost, n-1, dp));
        return ans;
    }
};