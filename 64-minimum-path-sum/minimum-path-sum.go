func minPathSum(grid [][]int) int {
    m := len(grid)
    n := len(grid[0])

    dp := make([]int, n)

    for i := 0; i < n; i++ {
        if i == 0 {
            dp[i] = grid[0][i]
            continue
        }
        dp[i] = grid[0][i] + dp[i-1]
    }

    for i := 1; i < m; i++ {
        tmp := make([]int, n)
        for j := 0; j < n; j++ {
            up := dp[j]
            left := math.MaxInt
            if j > 0 {
                left = tmp[j-1]
            }

            tmp[j] = grid[i][j] + min(up, left)
        }
        dp = tmp
    }

    return dp[n-1]
}