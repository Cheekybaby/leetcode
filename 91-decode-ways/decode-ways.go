func solve(s string, n int, dp []int) int {
    if n == len(s) {
        return 1
    }
    if s[n] == '0' {
        return 0
    }

    if dp[n] != -1 {
        return dp[n]
    }

    dp[n] = solve(s, n+1, dp)

    if (n < len(s)-1) && ((s[n] == '1') || (s[n] == '2' && s[n+1] <= '6')){
        dp[n] += solve(s, n+2, dp)
    }

    return dp[n]
}

func numDecodings(s string) int {
    dp := initDP(len(s))
    return solve(s, 0, dp)
}
func initDP(n int) (dp []int) {
    dp = make([]int, n+1)
    for i := range dp {
        dp[i] = -1
    }
    return dp
}