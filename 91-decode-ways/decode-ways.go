func solve(s string, idx int, dp []int) int {
    if idx == len(s) {
        return 1
    }
    if s[idx] == '0' {
        return 0
    }

    if dp[idx] != -1 {
        return dp[idx]
    }

    char := s[idx]

    ways := 0
    if idx < len(s)-1 && (char == '1' || (char == '2' && s[idx + 1] <= '6')) {
        ways += solve(s, idx+2, dp)
    }
    ways += solve(s, idx+1, dp)

    dp[idx] = ways

    return dp[idx]
}

func numDecodings(s string) int {
    dp := initDP(len(s))
    return solve(s, 0, dp)
}
func initDP(n int) (dp []int) {
    dp = make([]int, n+1)
    for i := range dp {
        dp[i] = -1
    }
    return dp
}