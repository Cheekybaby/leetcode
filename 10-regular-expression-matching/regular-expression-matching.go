func solve(s, p string, i, j int, dp [][]int) bool {
    if len(p) == j {
        if len(s) == i {
            return true
        } else {
            return false
        }
    }

    if dp[i][j] != -1 {
        return dp[i][j] == 1
    }

    firstMatch := false
    if i < len(s) && (p[j] == s[i] || p[j] == '.') {
        firstMatch = true
    }

    if j < len(p)-1 && p[j+1] == '*' {
        val := solve(s, p, i, j+2, dp) || (firstMatch && solve(s, p, i+1, j, dp))
        if val {
            dp[i][j] = 1
        } else {
            dp[i][j] = 0
        }
    } else {
        val := firstMatch && solve(s, p, i+1, j+1, dp)
        if val {
            dp[i][j] = 1
        } else {
            dp[i][j] = 0
        }
    }
    return dp[i][j] == 1
}

func isMatch(s string, p string) bool {
    dp := initializeArray(len(s), len(p));
    return solve(s, p, 0, 0, dp)
}

func initializeArray(n, m int) (matrix [][]int) {
    matrix = make([][]int, n+1)
    for i:= range matrix {
        matrix[i] = make([]int, m+1)
        for j := range matrix[i] {
            matrix[i][j] = -1
        }
    }
    return matrix
}