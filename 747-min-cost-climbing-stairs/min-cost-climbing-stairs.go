var dp = make([]int, 2000)
func solve(n int, cost []int) int {
    if n < 0 {
        return 0
    }
    if n == 0 || n == 1 {
        return cost[n]
    }

    if dp[n] != -1 {
        return dp[n]
    }

    dp[n] = cost[n] + min(solve(n-1, cost), solve(n-2, cost))
    return dp[n]
}

func minCostClimbingStairs(cost []int) int {
    n := len(cost)
    initDP()
    return min(solve(n-1, cost), solve(n-2, cost))
}

func initDP() {
    for i := range dp {
        dp[i] = -1
    }
}