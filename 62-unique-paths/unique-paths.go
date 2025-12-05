func solve(i, j int, dp [][]int) int {
    if i == 0 && j == 0 {
        return 1
    }
    if i < 0 || j < 0 {
        return 0
    }

    if dp[i][j] != -1 {
        return dp[i][j]
    }
    
    left := solve(i, j-1, dp)
    up := solve(i-1, j, dp)

    dp[i][j] = left + up

    return dp[i][j]
}

func uniquePaths(m int, n int) int {
    dp := make([][]int, m)
    for i := range dp {
        dp[i] = make([]int, n)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
    total_paths := solve(m-1, n-1, dp)
    return total_paths
}