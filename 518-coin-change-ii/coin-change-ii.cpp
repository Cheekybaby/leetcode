class Solution {
public:
    int solve(int amount, vector<int> &coins, int index, vector<vector<int>> &memo){
        if (amount == 0) return 1;
        if (amount < 0) return 0;
        if (index == coins.size()) return 0;
        if (memo[index][amount] != -1) return memo[index][amount];

        int not_take = solve(amount, coins, index + 1, memo);
        int take = 0;
        if (coins[index] <= amount){
            take = solve(amount - coins[index], coins, index, memo);
        }

        return memo[index][amount] = take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int> (amount + 1, -1));
        return solve(amount, coins, 0, memo);
    }
};