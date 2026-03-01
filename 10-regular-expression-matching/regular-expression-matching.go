func isMatch(s string, p string) bool {
    n, m := len(s), len(p)
    dp := make([][]bool, n+1)
    for i := range dp {
        dp[i] = make([]bool, m+1)
    }

    dp[n][m] = true

    for i := n; i >= 0; i-- {
        for j := m-1; j >= 0; j-- {
            var first_match bool = false
            if (i < n) && (s[i] == p[j] || p[j] == '.') { 
                first_match = true 
            }

            if (j + 1 < m) && p[j+1] == '*' {
                dp[i][j] = dp[i][j+2] || (first_match && dp[i+1][j])
            } else {
                dp[i][j] = first_match && dp[i+1][j+1]
            }
        }
    }
    return dp[0][0]
}