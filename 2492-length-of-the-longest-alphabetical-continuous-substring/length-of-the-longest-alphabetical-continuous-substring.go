func longestContinuousSubstring(s string) int {
    max_len := 1
    i, j := 1, 0
    for ; i < len(s); i++ {
        diff := s[i] - s[i-1]
        max_len = max(max_len, i - j)
        if diff == 1 {
            continue
        }
        j = i
    }

    max_len = max(max_len, i - j)

    return max_len
}