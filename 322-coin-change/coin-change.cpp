class Solution {
public:
    int solve(vector<int> &coins, int amount, unordered_map<int,int> &memo){
        if (amount < 0) return INT_MAX;
        if (amount == 0) return 0;
        if (memo.find(amount) != memo.end()) return memo[amount];

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
        unordered_map<int,int> memo;
        int ans = solve(coins, amount, memo);
        if (ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};