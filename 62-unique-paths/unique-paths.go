func uniquePaths(m int, n int) int {
    dp := make([]int, n)
    for i := range dp {
        dp[i] = 1
    }
    for i := 2; i <= m; i++ {
        tmp := make([]int, n)
        for j := 0; j < n; j++ {
            left := 0
            if j > 0 {
                left = tmp[j-1]
            }   
            up := dp[j]
            
            tmp[j] = left + up
        }
        dp = tmp
    }

    return dp[n-1]
}