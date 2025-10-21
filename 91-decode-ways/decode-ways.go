func numDecodings(s string) int {
    if s[0] == '0' {
        return 0
    }
    n := len(s)
    dp := make([]int, n+1)
    dp[0] = 1

    for i := 0; i < n; i++ {
        ways := 0
        
        if s[i] != '0' {
            ways += dp[i]
        }
        if i > 0 && (s[i-1] == '1' || (s[i] <= '6' && s[i-1] == '2')) {
            ways += dp[i-1]
        }
        dp[i+1] = ways
    }

    return dp[n]
}