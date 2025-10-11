func minPathSum(grid [][]int) int {
    m := len(grid)
    n := len(grid[0])

    dp := make([]int, n)
    const val = 50000
    for i := 0; i < n; i++ {
        if i == 0 {
            dp[i] = grid[0][i]
            continue
        }
        dp[i] = dp[i-1] + grid[0][i]
    }

    for i := 2; i <= m; i++ {
        tmp := make([]int, n)
        for j := 0; j < n; j++ {
            up := dp[j]
            left := val
            if j > 0 {
                left = tmp[j-1]
            }
            tmp[j] = grid[i-1][j] + min(left, up)
        }
        dp = tmp
    }

    return dp[n-1]
}