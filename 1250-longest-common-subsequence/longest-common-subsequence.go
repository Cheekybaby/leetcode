func solve(s, t string, i, j int, dp [][]int) int {
    if i >= len(s) || j >= len(t) {
        return 0
    }

    if dp[i][j] != -1 {
        return dp[i][j]
    }

    if s[i] == t[j] {
        dp[i][j] = 1 + solve(s, t, i + 1, j + 1, dp)
    } else {
        dp[i][j] = max(solve(s, t, i + 1, j, dp), solve(s, t, i, j + 1, dp))
    }
    return dp[i][j]
}

func longestCommonSubsequence(text1 string, text2 string) int {
    n, m := len(text1), len(text2)
    dp := make([][]int, n)
    for i := range dp {
        dp[i] = make([]int, m)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
    return solve(text1, text2, 0, 0, dp)
}