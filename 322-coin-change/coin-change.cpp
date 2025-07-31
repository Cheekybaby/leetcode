class Solution {
public:
    int solve(vector<int> &c, int amount, vector<int> &dp){
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;
        if (dp[amount] != -1) return dp[amount];
        int coins = INT_MAX;
        for(auto i:c){
            int coin = solve(c, amount - i, dp);

            if (coin != INT_MAX){
                coins = min(coins, 1+coin);
            }
        }

        return dp[amount] = coins;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, -1);
        int ans = solve(coins, amount, dp);

        return (ans == INT_MAX) ? -1 : ans;
    }
};