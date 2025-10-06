func solve(s, p string, n, m int, dp [][]int) int {
    if n == len(s) && m == len(p) {
        return 1
    }

    if m == len(p) && n < len(s) {
        return 0
    }

    if n == len(s) && m < len(p) {
        for l := m; l < len(p); l++ {
            if p[l] != '*' {
                return 0
            }
        }
        return 1
    }

    if dp[n][m] != -1 {
        return dp[n][m]
    }


    if s[n] == p[m] {
        dp[n][m] = solve(s, p, n+1, m+1, dp)
    } else {
        if p[m] == '?' {
            dp[n][m] = solve(s, p, n+1, m+1, dp)
        } else if p[m] == '*' {
            val := solve(s, p, n+1, m, dp) + solve(s, p, n, m+1, dp)
            if val > 0 {
                dp[n][m] = 1
            } else {
                dp[n][m] = 0
            }
        } else { 
            dp[n][m] = 0
        }
    }
    return dp[n][m]
}

func isMatch(s string, p string) bool {
    dp := initDP(len(s), len(p))
    return (solve(s, p, 0, 0, dp) == 1)
}
func initDP(n, m int) (dp [][]int) {
    dp = make([][]int, n+1)
    for i := range dp {
        dp[i] = make([]int, m+1)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
    return dp
}