func isInterleave(s1 string, s2 string, s3 string) bool {
    n, m := len(s1), len(s2)
    if (n + m) != len(s3) {
        return false
    }
    
    dp := initDP(n, m)
    dp[0][0] = true
    
    for i := 1; i <= n; i++ {
        if dp[i-1][0] && s1[i-1] == s3[i-1] {
            dp[i][0] = true
        }
    }

    for j := 1; j <= m; j++ {
        if dp[0][j-1] && s2[j-1] == s3[j-1] {
            dp[0][j] = true
        }
    }

    for i := 1; i <= n; i++ {
        for j := 1; j <= m; j++ {
            if (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]) {
                dp[i][j] = true
            }
        }
    }

    return dp[n][m]
}

func initDP(n, m int) (dp [][]bool) {
    dp = make([][]bool, n+1)
    for i := range dp {
        dp[i] = make([]bool, m+1)
    }

    return dp
}