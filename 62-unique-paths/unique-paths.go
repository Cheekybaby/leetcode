func solve(m, n, i, j int, dp [][]int) int {
    if i == m-1 && j == n-1 {
        return 1
    }

    if i >= m || j >= n {
        return 0
    }

    if dp[i][j] != -1 {
        return dp[i][j]
    }

    dp[i][j] = solve(m, n, i+1, j, dp) + solve(m, n, i, j+1, dp)

    return dp[i][j]
}

func uniquePaths(m int, n int) int {
    dp := initializeDP(m, n)
    return solve(m, n, 0, 0, dp)
}

func initializeDP(m, n int) (matrix [][]int) {
    matrix = make([][]int, m)
    for i := range matrix {
        matrix[i] = make([]int, n)
        for j := range matrix[i] {
            matrix[i][j] = -1
        }
    }
    return matrix
}