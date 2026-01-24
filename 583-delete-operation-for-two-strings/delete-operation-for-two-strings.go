func minDistance(word1 string, word2 string) int {
    n, m := len(word1), len(word2)
    dp := make([]int, m+1)
    for i := 1; i <= n; i++ {
        temp := make([]int, m+1)
        for j := 1; j <= m; j++ {
            if word1[i-1] == word2[j-1] {
                temp[j] = 1 + dp[j-1]
            } else {
                temp[j] = max(dp[j], temp[j-1])
            }
        }
        dp = temp
    }

    return (n + m - (2 * dp[m]))
}