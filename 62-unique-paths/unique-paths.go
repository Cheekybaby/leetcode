func solve(m, n int, dp [][]int) int {
    if m == 1 && n == 1 {
        return 1
    }
    if m < 1 || n < 1 {
        return 0
    }

    if dp[m][n] != -1 {
        return dp[m][n]
    }

    left := solve(m, n-1, dp)
    up := solve(m-1, n, dp)

    dp[m][n] = (left + up)

    return dp[m][n]
}

func uniquePaths(m int, n int) int {
    dp := initDP(m, n)
    return solve(m, n, dp)
}
func initDP(m, n int) (dp [][]int) {
    dp = make([][]int, m+1)
    for i := range dp {
        dp[i] = make([]int, n+1)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }

    return dp
}