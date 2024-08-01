/**
 * @param {number[]} cost
 * @return {number}
 */

var totalCost = function(cost, n, memo){
    if (n in memo) return memo[n];
    if (n<0) return 0;
    if (n === 0 || n === 1){
        return cost[n];
    }

    memo[n] = cost[n] + Math.min(totalCost(cost, n-1, memo), totalCost(cost, n-2, memo));
    return memo[n];
}
var minCostClimbingStairs = function(cost) {
    const n = cost.length;
    let memo = {};
    return Math.min(totalCost(cost, n-1, memo), totalCost(cost, n-2, memo));
};