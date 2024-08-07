class Solution {
public:
    int solve(vector<int> &coins, int amount, vector<int> &memo){
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;
        if (memo[amount] != -1) return memo[amount];

        int ans = INT_MAX;

        for (int coin: coins){
            int res = solve(coins, amount - coin, memo);

            if (res != INT_MAX){
                ans = min(ans, 1 + res);
            }
        }
        memo[amount] = ans;
        return memo[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(10001, -1);
        int ans = solve(coins, amount, memo);
        return (ans == INT_MAX) ? -1 : ans;
    }
};