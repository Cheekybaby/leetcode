class Solution {
public:
    int solve(vector<int>& coins, int amount, int n, vector<vector<int>> &dp) {
        if (amount < 0) return 0;
        if (amount == 0) return 1;
        if (n < 0) return 0;
        if (dp[n][amount] != -1) return dp[n][amount];

        int not_take = solve(coins, amount, n-1,  dp);
        int take = 0;
        if (amount >= coins[n]){
            take = solve(coins, amount-coins[n], n, dp);
        }

        return dp[n][amount] = take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        int ans = solve(coins, amount, n-1, dp);
        return ans;
    }
};