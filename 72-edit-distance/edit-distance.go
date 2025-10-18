func solve(s, t string, i, j int, dp [][]int) int {
	if i == len(s) {
		return len(t) - j
	}
	if j == len(t) {
		return len(s) - i
	}

    if dp[i][j] != -1 {
        return dp[i][j]
    }

	if s[i] == t[j] {
		dp[i][j] = solve(s, t, i+1, j+1, dp)
	} else {
		dp[i][j] = 1 + min(solve(s, t, i+1, j+1, dp), min(solve(s, t, i+1, j, dp), solve(s, t, i, j+1, dp)))
	}

    return dp[i][j]
}

func minDistance(word1 string, word2 string) int {
    dp := initDP(len(word1), len(word2))
	return solve(word1, word2, 0, 0, dp)
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