func minPathSum(grid [][]int) int {
    m := len(grid)
    n := len(grid[0])

    dp := make([][]int, m+1)
    for i := range dp {
        dp[i] = make([]int, n+1)
    }
    const val = 50000
    for i := 0; i <= m; i++ {
        dp[i][0] = val
    }
    for i := 0; i <= n; i++ {
        dp[0][i] = val
    }

    dp[1][1] = grid[0][0]

    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            if i == 1 && j == 1 {
                continue
            }
            dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j], dp[i][j-1])
        }
    }

    return dp[m][n]
}