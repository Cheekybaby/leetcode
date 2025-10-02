func solve(s, t string, n, m int, dp [][]int) int {
    if n < 0 || m < 0 {
        return 0
    }

    if dp[n][m] != -1 {
        return dp[n][m]
    }

    if s[n] == t[m] {
        dp[n][m] = 1 + solve(s, t, n-1, m-1, dp)
    } else {
        dp[n][m] = max(solve(s, t, n-1, m, dp), solve(s, t, n, m-1, dp))
    }
    return dp[n][m]
}

func longestPalindromeSubseq(s string) int {
    n := len(s)
    var t string
    for i := n-1; i >= 0; i-- {
        t += string(s[i])
    }
    dp := initDP(n)
    return solve(s, t, n-1, n-1, dp)
}
func initDP(n int) (dp [][]int) {
    dp = make([][]int, n)
    for i := range dp {
        dp[i] = make([]int, n)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
    return dp
}