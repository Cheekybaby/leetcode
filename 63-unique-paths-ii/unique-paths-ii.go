func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    m := len(obstacleGrid)
    n := len(obstacleGrid[0])

    dp := make([]int, n)
    flag := false
    for i := 0; i < n; i++ {
        if obstacleGrid[0][i] == 1 {
            flag = true
        }
        if flag {
            dp[i] = 0
        } else {
            dp[i] = 1
        }
    }

    for i := 2; i <= m; i++ {
        tmp := make([]int, n)
        for j := 0; j < n; j++ {
            up := dp[j]
            left := 0
            if j > 0 {
                left = tmp[j-1]
            }

            if obstacleGrid[i-1][j] == 1 {
                tmp[j] = 0
            } else {
                tmp[j] = up + left
            }
        }
        dp = tmp
    }
    return dp[n-1]
}