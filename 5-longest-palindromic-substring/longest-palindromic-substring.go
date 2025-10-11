func longestPalindrome(s string) string {
    n := len(s)
    dp := make([][]bool, n)
    for i := range dp {
        dp[i] = make([]bool, n)
        for j := range dp[i] {
            dp[i][j] = false
        }
    }
    max_len := 1
    idx := 0
    // Length 1
    for i := range s {
        dp[i][i] = true
    }

    // Length 2
    for i := 1; i < n; i++ {
        if s[i] == s[i-1] {
            dp[i-1][i] = true
            idx = i-1
            max_len = 2
        }
    }

    // Length 3 and above
    for len := 3; len <= n; len++ {
        l, r := 0, len-1
        for r < n {
            if s[l] == s[r] && dp[l+1][r-1] {
                dp[l][r] = true
                idx = l
                max_len = len
            }
            r++
            l++
        }
    }

    return s[idx:idx+max_len]
}