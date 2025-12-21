func countSubstrings(s string, c byte) int64 {
    var cnt int64
    for i := range s {
        if s[i] == c {
            cnt++
        }
    }

    total_substrings := (cnt * (cnt + 1))/2

    return total_substrings
}