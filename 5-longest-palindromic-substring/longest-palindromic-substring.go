func longestPalindrome(s string) string {
    n := len(s)
    dp := make([][]bool, n)
    for i := range dp {
        dp[i] = make([]bool, n)
    }

    idx := 0
    max_len := 1

    // Length 1
    for i := 0; i < n; i++ {
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

    // Length 3 and beyond
    for length := 3; length <= n; length++ {
        i, j := 0, length-1
        for j < n {
            if s[i] == s[j] && dp[i+1][j-1] {
                dp[i][j] = true
                idx = i
                max_len = length
            }
            j++
            i++
        }
    }

    return s[idx:idx+max_len]
}