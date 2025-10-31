func dfs(adj map[string][]string, idx string, dp map[string]int) int {
    if _, ok := adj[idx]; !ok {
        return 0
    }

    if val, ok := dp[idx]; ok {
        return val
    }

    longest := math.MinInt
    for _, str := range adj[idx] {
        val := 1 + dfs(adj, str, dp)

        longest = max(val, longest)
    }

    dp[idx] = longest

    return dp[idx]
}

func longestStrChain(words []string) int {
    dp := make(map[string]int)
    buckets := make([][]string, 16)
    for i := range words {
        idx := len(words[i])-1
        buckets[idx] = append(buckets[idx], words[i])
    }

    adj := make(map[string][]string)
    
    for i := 0; i < len(buckets)-1; i++ {
        if len(buckets[i]) == 0 || len(buckets[i+1]) == 0 {
            continue
        }

        for _, str := range buckets[i] {
            for _, s := range buckets[i+1] {
                if isValid(str, s) {
                    adj[str] = append(adj[str], s)
                }
            }
        }
    }

    longest := math.MinInt

    for key, _ := range adj {
        val := dfs(adj, key, dp)
        longest = max(longest, val)
    }

    if longest == math.MinInt {
        return 1
    }
    return longest + 1
}

func isValid(s, t string) bool {
    if len(t) != len(s)+1 {
        return false
    }

    i, j := 0, 0
    mismatch := 0

    for i < len(t) && j < len(s) {
        if t[i] != s[j] {
            mismatch++
            i++
            if mismatch > 1 {
                return false
            }
        } else {
            i++
            j++
        }
    }

    return true
}