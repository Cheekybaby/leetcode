func minimumTotal(triangle [][]int) int {
    m := len(triangle)
    dp := make([]int, 1)
    dp[0] = triangle[0][0]

    for i := 2; i <= m; i++ {
        n := len(dp)+1
        tmp := make([]int, n)
        for j := 0; j < n; j++ {
            left := math.MaxInt
            if j > 0 {
                left = dp[j-1]
            }
            above := math.MaxInt
            if j < n-1 {
                above = dp[j]
            }

            tmp[j] = triangle[i-1][j] + min(left, above)
        }
        dp = tmp
    }
    min_cost := dp[0]
    for i := 0; i < len(dp); i++ {
        min_cost = min(min_cost, dp[i])
    }

    return min_cost
}