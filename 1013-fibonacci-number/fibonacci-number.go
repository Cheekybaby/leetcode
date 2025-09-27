var dp = make([]int, 32);
func solve(n int) int {
    if n == 0 {
        return 0
    }
    if n == 1 {
        return 1
    }
    if dp[n] != -1 {
        return dp[n]
    }
    dp[n] = solve(n-1) + solve(n-2)
    return dp[n]
}
func fib(n int) int {
    initDP()
    return solve(n)
}

func initDP() {
    for i := range dp {
        dp[i] = -1
    }
}