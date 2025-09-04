func solve(cost []int, idx int, dp []int) int {
    if idx >= len(cost) {
        return 0
    }
    if idx == len(cost)-1 {
        return cost[idx]
    }

    if dp[idx] != -1 {
        return dp[idx]
    }

    dp[idx] = cost[idx] + min(solve(cost, idx+1, dp), solve(cost, idx+2, dp))
    return dp[idx]
}

func minCostClimbingStairs(cost []int) int {
    dp := initDP(len(cost))
    return min(solve(cost, 0, dp), solve(cost, 1, dp))
}

func initDP(n int) (dp []int) {
    dp = make([]int, n+1)

    for i := range dp {
        dp[i] = -1
    }

    return dp
}