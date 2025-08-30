func solve(s, p string, i, j int, dp [][]int) bool {
    if j == len(p) {
        return i == len(s)
    }

    if dp[i][j] != -1 {
        return dp[i][j] == 1
    }

    firstMatch := (i < len(s)) && (s[i] == p[j] || p[j] == '.')

    if j < len(p)-1 && p[j+1] == '*' {
        dp[i][j] = 0
        val := (firstMatch && solve(s, p, i+1, j, dp)) || (solve(s, p, i, j+2, dp))
        if val {
            dp[i][j] = 1
        }
    } else {
        dp[i][j] = 0
        val := (firstMatch && solve(s, p, i+1, j+1, dp))
        if val {
            dp[i][j] = 1
        }
    }
    return dp[i][j] == 1
}
func isMatch(s string, p string) bool {
    dp := initializeDP(len(s), len(p))
    return solve(s, p, 0, 0, dp)
}

func initializeDP(n, m int) (matrix [][]int) {
    matrix = make([][]int, n+1)
    for i := range matrix {
        matrix[i] = make([]int, m+1)
        for j := range matrix[i] {
            matrix[i][j] = -1
        }
    }
    return matrix
}