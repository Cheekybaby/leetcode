class Solution:
    def totalCost(self, cost: List[int], n: int, memo: dict[int,int]) -> int:
        if (n < 0):
            return 0
        if (n == 0 or n == 1):
            return cost[n]

        if n not in memo:
            memo[n] = cost[n] + min(self.totalCost(cost, n-1, memo), self.totalCost(cost, n-2, memo))
        return memo[n]


    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        memo = {}
        return min(self.totalCost(cost, n-1, memo), self.totalCost(cost, n-2, memo))