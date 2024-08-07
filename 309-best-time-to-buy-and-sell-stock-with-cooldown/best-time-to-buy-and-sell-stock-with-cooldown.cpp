class Solution {
public:
    int solve(vector<int> &prices, int buy, int index, vector<vector<int>> &memo){
        if (index >= prices.size()) return 0;
        if (memo[index][buy] != -1) return memo[index][buy];
        if (buy){
            int buys = -prices[index] + solve(prices, 0, index + 1, memo);
            int not_buys = solve(prices, 1, index + 1, memo);
            memo[index][buy] = max(buys, not_buys);
            return memo[index][buy];
        } else {
            int buys = prices[index] + solve(prices, 1, index + 2, memo);
            int not_buys = solve(prices, 0, index + 1, memo);
            memo[index][buy] = max(buys, not_buys);
            return memo[index][buy];
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> memo(prices.size(), vector<int> (2, -1));
        return solve(prices, 1, 0, memo);
    }
};