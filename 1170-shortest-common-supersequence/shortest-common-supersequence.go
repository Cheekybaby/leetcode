func shortestCommonSupersequence(str1 string, str2 string) string {
    n, m := len(str1), len(str2)
    dp := make([]string, m+1)
    for i := range m+1 {
        dp[i] = str2[:i]
    }

    fmt.Println(dp)

    for i := 1; i <= n; i++ {
        temp := make([]string, m+1)
        temp[0] = str1[:i]

        for j := 1; j <= m; j++ {
            if str1[i-1] == str2[j-1] {
                temp[j] = dp[j-1] + string(str1[i-1])
            } else {
                s1 := dp[j]
                s2 := temp[j-1]

                if len(s1) < len(s2) {
                    temp[j] = s1 + string(str1[i-1])
                } else {
                    temp[j] = s2 + string(str2[j-1])
                }
            }
        }

        copy(dp, temp)
    }

    return dp[m]
}