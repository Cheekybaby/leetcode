class Solution {
public:
    int solve(vector<int> &coins, int amount, vector<int> &memo){
        if (amount < 0) return INT_MAX;
        if (amount == 0) return 0;
        if (memo[amount] != -1) return memo[amount];

        int minCoins = INT_MAX;

        for (int i=0; i<coins.size(); i++){
            int res = solve(coins, amount - coins[i], memo);

            if (res != INT_MAX){
                minCoins = min(minCoins, 1 + res);
            }
        }
        memo[amount] = minCoins;
        return memo[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> memo(10001, -1);
        int ans = solve(coins, amount, memo);
        if (ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};