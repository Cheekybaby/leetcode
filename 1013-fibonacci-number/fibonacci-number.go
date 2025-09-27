func solve(n int, dp []int) int {
    if n == 0 {
        return 0
    }
    if n == 1 {
        return 1
    }
    if dp[n] != -1 {
        return dp[n]
    }
    dp[n] = solve(n-1, dp) + solve(n-2, dp)
    return dp[n]
}
func fib(n int) int {
    dp := initDP(n)
    return solve(n, dp)
}

func initDP(n int) (dp []int) {
    dp = make([]int, n+1)
    for i := range dp {
        dp[i] = -1
    }
    return dp
}