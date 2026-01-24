func longestCommonSubsequence(text1 string, text2 string) int {
    n, m := len(text1), len(text2)
    dp := make([]int, m+1)
    for i := 1; i <= n; i++ {
        temp := make([]int, m+1)
        for j := 1; j <= m; j++ {
            if text1[i-1] == text2[j-1] {
                temp[j] = 1 + dp[j-1]
            } else {
                temp[j] = max(dp[j], temp[j-1])
            }
        }
        dp = temp
    }

    return dp[m]
}