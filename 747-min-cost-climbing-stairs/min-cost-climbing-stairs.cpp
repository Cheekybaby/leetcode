class Solution {
public:
    int totalCost(vector<int> &cost , int n, vector<int> &memo){
        if (memo[n]!=-1) return memo[n];
        if (n < 0) return 0;
        if (n == 0 || n == 1) return cost[n];
        memo[n] = cost[n] + min(totalCost(cost, n-1, memo), totalCost(cost, n-2, memo));
        return memo[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(1001, -1);
        return min(totalCost(cost, n-1, memo), totalCost(cost, n-2, memo));
    }
};