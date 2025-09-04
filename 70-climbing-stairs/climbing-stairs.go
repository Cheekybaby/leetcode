func solve(n, i int, dp []int) int {
    if i > n {
        return 0
    }
    if i == n || i == n-1 {
        return 1
    }

    if dp[i] != -1 {
        return dp[i]
    }

    dp[i] = solve(n, i+1, dp) + solve(n, i+2, dp)

    return dp[i]
}

func climbStairs(n int) int {
    dp := initDP(n)
    return solve(n, 0, dp)
}

func initDP(n int) (dp []int) {
    dp = make([]int, n+1)

    for i := range dp {
        dp[i] = -1
    }
    return dp
}