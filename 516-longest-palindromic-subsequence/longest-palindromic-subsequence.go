func longestPalindromeSubseq(s string) int {
    n := len(s)
    dp := make([][]int, n+2)
    for i := range dp {
        dp[i] = make([]int, n+2)
    }

    for i := n-1; i >= 0; i-- {
        for j := 0; j < n; j++ {
            if s[i] == s[j] {
                dp[i+1][j+1] = 1 + dp[i+2][j]
            } else {
                dp[i+1][j+1] = max(dp[i+2][j+1], dp[i+1][j])
            }
        }
    }

    return dp[1][n]
}