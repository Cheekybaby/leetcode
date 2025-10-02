func solve(s, t string, n, m int, dp [][]int) int {
    if n < 0 || m < 0 {
        return 0
    }

    if dp[n][m] != -1 {
        return dp[n][m]
    }

    if s[n] == t[m] {
        dp[n][m] = 1 + solve(s, t, n-1, m-1, dp)
    } else {
        dp[n][m] = max(solve(s, t, n-1, m, dp), solve(s, t, n, m-1, dp))
    }
    return dp[n][m]
}
func minDistance(word1 string, word2 string) int {
    n, m := len(word1), len(word2)
    dp := initDP(n, m)
    longest_subseq := solve(word1, word2, n-1, m-1, dp)

    return (n + m - (2 * longest_subseq))
}
func initDP(n, m int) (dp [][]int) {
    dp = make([][]int, n)
    for i := range dp {
        dp[i] = make([]int, m)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
    return dp
}