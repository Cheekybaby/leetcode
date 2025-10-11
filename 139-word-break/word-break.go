func solve(s string, idx int, dict []string, dp []int) bool {
	if idx < 0 {
		return true
	}

    if dp[idx] != -1 {
        return dp[idx] == 1
    }

	dp[idx] = 0
	for _, str := range dict {
		length := len(str)
		if idx-length+1 < 0 {
			continue
		}
		if (s[idx-length+1:idx+1] == str) && solve(s, idx-length, dict, dp) {
			dp[idx] = 1
		}
	}

    return dp[idx] == 1
}

func wordBreak(s string, wordDict []string) bool {
    dp := initDP(len(s))
	return solve(s, len(s)-1, wordDict, dp)
}
func initDP(n int) (dp []int) {
    dp = make([]int, n)
    for i := range dp {
        dp[i] = -1
    }
    return dp
}