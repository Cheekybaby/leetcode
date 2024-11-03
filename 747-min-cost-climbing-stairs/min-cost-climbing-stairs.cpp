class Solution {
public:
    int solve(vector<int> &cost, int index, vector<int> &memo){
        if (index < 0) return 0;
        if (index == 0 || index == 1) return cost[index];
        if (memo[index] != -1) return memo[index];

        return memo[index] = cost[index] + min(solve(cost, index-1, memo), solve(cost, index-2, memo));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(solve(cost, cost.size()-1, dp), solve(cost, cost.size()-2, dp));
    }
};