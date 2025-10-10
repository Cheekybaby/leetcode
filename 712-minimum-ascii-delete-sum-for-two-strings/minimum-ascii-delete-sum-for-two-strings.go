func solve(s, t string, n, m int, dp [][]int) int {
    if n == len(s) {
        sum := 0
        for m < len(t) {
            sum += int(t[m])
            m++
        }
        return sum
    }
    if m == len(t) {
        sum := 0
        for n < len(s) {
            sum += int(s[n])
            n++
        }
        return sum
    }

    if dp[n][m] != -1 {
        return dp[n][m]
    }

    if s[n] == t[m] {
        dp[n][m] = solve(s, t, n+1, m+1, dp)
    } else {
        take_one := int(s[n]) + solve(s, t, n+1, m, dp)
        take_two := int(t[m]) + solve(s, t, n, m+1, dp)
        take_none := int(t[m]) + int(s[n]) + solve(s, t, n+1, m+1, dp)

        dp[n][m] = min(take_one, min(take_two, take_none))
    }
    return dp[n][m]
}

func minimumDeleteSum(s1 string, s2 string) int {
    dp := initDP(len(s1), len(s2))
    return solve(s1, s2, 0, 0, dp)
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