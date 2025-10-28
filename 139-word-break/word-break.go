func solve(s string, wordDict []string, idx int, dp []int) bool {
    if idx >= len(s) {
        return true
    }

    if dp[idx] != -1 {
        return dp[idx] == 1
    }

    dp[idx] = 0

    for _, str := range wordDict {
        length := len(str)

        if idx+length > len(s) {
            continue
        }

        if (s[idx:idx+length] == str) && solve(s, wordDict, idx+length, dp) {
            dp[idx] = 1
        }
    }

    return dp[idx] == 1
}

func wordBreak(s string, wordDict []string) bool {
    dp := initDP(len(s))
    return solve(s, wordDict, 0, dp)
}

func initDP(n int) (dp []int) {
    dp = make([]int, n+1)
    for i := range dp {
        dp[i] = -1
    }

    return dp
}