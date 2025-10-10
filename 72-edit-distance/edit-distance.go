func solve(s, t string, n, m int, dp [][]int) int {
	if n == len(s) {
		return len(t) - m
	}
	if m == len(t) {
		return len(s) - n
	}

	if dp[n][m] != -1 {
		return dp[n][m]
	}

	if s[n] == t[m] {
		dp[n][m] = solve(s, t, n+1, m+1, dp)
	} else {
		dp[n][m] = 1 + min(solve(s, t, n+1, m+1, dp), min(solve(s, t, n, m+1, dp), solve(s, t, n+1, m, dp)))
	}
	return dp[n][m]
}

func minDistance(word1 string, word2 string) int {
	dp := initDP(len(word1), len(word2))
	return solve(word1, word2, 0, 0, dp)
}
func initDP(n, m int) (dp [][]int) {
	dp = make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, m + 1)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}
	return dp
}