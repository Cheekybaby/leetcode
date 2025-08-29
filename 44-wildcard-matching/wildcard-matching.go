func solve(s, p string, i, j int, dp [][]int) bool {
    if i == len(s) && j == len(p) { // Successfully checked both strings
        return true
    }
    if j == len(p) && i < len(s) { // Pattern ended but string didn't
        return false
    }

    if i == len(s) && j < len(p) { // String ended but pattern didn't
        dp[i][j] = 1
        for l:=j; l<len(p); l++ { // No problem if the only characters left in p are *
            if p[l] != '*' {
                dp[i][j] = 0
                break
            }
        }
        return dp[i][j] == 1
    }
    if dp[i][j] != -1 {
        return dp[i][j] == 1
    }

    // If the current pattern's character is not a *
    if p[j] != '*' {
        if p[j] == s[i] || p[j] == '?' {
            val := solve(s, p, i+1, j+1, dp)
            if val == true {
                dp[i][j] = 1
            } else {
                dp[i][j] = 0
            }
            return dp[i][j] == 1
        } else {
            dp[i][j] = 0
            return dp[i][j] == 1
        }
    } else {
        // We can either take it or not
        val := solve(s, p, i+1, j, dp) || solve(s, p, i, j+1, dp)
        if val == true {
            dp[i][j] = 1
        } else {
            dp[i][j] = 0
        }
        return dp[i][j] == 1
    }
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