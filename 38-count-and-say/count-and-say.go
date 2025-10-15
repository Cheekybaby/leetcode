func helper(s string) string {
    var res string
    for i := 0; i < len(s); i++ {
        char := s[i]
        count := 0
        for i < len(s) && s[i] == char {
            count++
            i++
        }

        res += (toString(count) + string(char))
        i--
    }

    return res
}
func countAndSay(n int) string {
    dp := make([]string, n)
    
    dp[0] = "1"

    for i := 1; i < n; i++ {
        dp[i] = helper(dp[i-1])
    }
    return dp[n-1]
}
func toString(n int) string {
    return strconv.Itoa(n)
}