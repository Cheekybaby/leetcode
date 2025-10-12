func solve(s string, i, j int, dp [][]int) int {
    if i >= len(s) || j < 0 {
        return 0
    }

    if dp[i][j] != -1 {
        return dp[i][j]
    }

    if s[i] == s[j] {
        dp[i][j] = 1 + solve(s, i+1, j-1, dp)
    } else {
        dp[i][j] = max(solve(s, i+1, j, dp), solve(s, i, j-1, dp))
    }
    
    return dp[i][j]
}

func longestPalindromeSubseq(s string) int {
    dp := initDP(len(s))
    return solve(s, 0, len(s)-1, dp)
}
func initDP(n int) (dp [][]int) {
    dp = make([][]int, n+1)
    for i := range dp {
        dp[i] = make([]int, n+1)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
    return dp
}